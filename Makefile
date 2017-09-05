all: cpp_go go_go

cpp_go: lncc.cpp
	g++ lncc.cpp -O -Wall --std=c++11 -o lncc
go_go: lncg.go
	go build lncg.go
