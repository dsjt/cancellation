gmpincl=/usr/local/Cellar/gmp/6.1.0/include
gmplib=/usr/local/Cellar/gmp/6.1.0/lib
CC=gcc
CXX=g++

reccur: reccur.cpp
	$(CXX) -std=c++11 -o $@ -L$(gmplib) -I$(gmpincl) -lgmp -lgmpxx $<

gauss_elim: gauss_elim.cpp
	$(CXX) -std=c++11 -o $@ -L$(gmplib) -I$(gmpincl)  -lgmp -lgmpxx $<
