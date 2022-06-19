#!/bin/sh

BUILDIR=build
cmake -S . -B $BUILDIR
cmake --build $BUILDIR

