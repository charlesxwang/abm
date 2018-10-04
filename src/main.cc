#include "omp.h"

#include <chrono>
#include <ctime>
#include <memory>

#include "graph.h"
#include "router.h"

int main(int argc, char** argv) {
  const bool directed = true;
  auto graph = std::make_unique<abm::Graph>(directed);
  if (argc > 1) {
    // Read MatrixMarket file
    const std::string filename = argv[1];
    graph->read_graph_matrix_market(filename);
  } else {
    // Generate a simple graph
    graph->generate_simple_graph();
  }

  auto router = std::make_unique<abm::Router>(10);
  router->read_od_pairs("../sf-od-50000.csv");

  const auto routes = router->od_pairs();

  // Paths (vector of edges)
  std::vector<std::pair<abm::graph::vertex_t, abm::graph::vertex_t>> path;
  path.reserve(graph->nedges());
  std::vector<std::pair<abm::graph::vertex_t, abm::graph::vertex_t>> sp;
  unsigned i = 0;
#pragma omp parallel for schedule(dynamic)
  for (i = 0; i < 5000; ++i) {
    // auto start = std::chrono::system_clock::now();
    // const auto distances = graph->dijkstra_priority_queue(1, -1);
    // std::cout << "O-D: " << route.first << "\t" << route.second << "\n";
    sp = graph->dijkstra(routes[i].first, routes[i].second);

#pragma omp critical
    path.insert(std::end(path), std::begin(sp), std::end(sp));

    // auto end = std::chrono::system_clock::now();
    /*
    std::cout << "Total path size: " << path.size() << "\n";
    std::cout << "elapsed time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << "ms\n";
    */
    // std::cout << i << "\n";
  }

  /*
  auto start = std::chrono::system_clock::now();
  const auto path = graph->dijkstra(1020, 20);
  auto end = std::chrono::system_clock::now();


  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   elapsed_seconds)
                   .count()
            << "ms\n";
  std::cout << "Dijkstra PriorityQueue\n";
  for (const auto& vertex : path) std::cout << vertex << "\t";
  /*
  unsigned i = 0;
  for (const auto& distance : sp.distances) {
    std::cout << i << "\t" << distance << "\n";
    ++i;
  }
  */
}
