# City-Scale Agent Based Modelling
> CB-Cities

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/cb-cities/abm/develop/license.md)
[![Developer docs](https://img.shields.io/badge/developer-docs-blue.svg)](http://cb-cities.github.io/abm)
[![CircleCI](https://circleci.com/gh/cb-cities/abm.svg?style=svg)](https://circleci.com/gh/cb-cities/abm)
[![codecov](https://codecov.io/gh/cb-cities/abm/branch/develop/graph/badge.svg)](https://codecov.io/gh/cb-cities/abm)
[![](https://img.shields.io/github/issues-raw/cb-cities/abm.svg)](https://github.com/cb-cities/abm/issues)
[![Project management](https://img.shields.io/badge/projects-view-ff69b4.svg)](https://github.com/cb-cities/abm/projects/)


## Compile

* Run `mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release /path/to/CMakeLists.txt`.

* Run `make clean && make -jN` (where N is the number of cores).

## Run 

* To run the abm from build directory, `./abm ../network.mtx ../sf-od-50k.csv`. 


### Run tests

* Run `./abmtest -s` (for a verbose output) or `ctest -VV`.

* Run `./abmtest -l` to see available test options
