CXX?=g++
CXXFLAGS=-std=c++14 -Wall -Wextra -g -I../../googletest/googletest/include -I..
LDFLAGS=-L../../googletest/googlemock/gtest -lgtest -lpthread
TARGET=test

TESTCASES  =
TESTCASES += testcases/constructor.o
TESTCASES += testcases/assignment.o
TESTCASES += testcases/typecast.o
TESTCASES += testcases/accessors.o
TESTCASES += testcases/and.o
TESTCASES += testcases/or.o
TESTCASES += testcases/xor.o
TESTCASES += testcases/invert.o
TESTCASES += testcases/leftshift.o
TESTCASES += testcases/rightshift.o
TESTCASES += testcases/logical.o
TESTCASES += testcases/gt.o
TESTCASES += testcases/gte.o
TESTCASES += testcases/lt.o
TESTCASES += testcases/lte.o
TESTCASES += testcases/equals.o
TESTCASES += testcases/notequals.o
TESTCASES += testcases/add.o
TESTCASES += testcases/sub.o
TESTCASES += testcases/mult.o
TESTCASES += testcases/div.o
TESTCASES += testcases/mod.o
TESTCASES += testcases/fix.o
TESTCASES += testcases/unary.o
TESTCASES += testcases/functions.o
TESTCASES += testcases/type_traits.o

all: $(TARGET)

.PHONY: clean

$(TESTCASES): %.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): test.cc $(TESTCASES)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f $(TESTCASES)
