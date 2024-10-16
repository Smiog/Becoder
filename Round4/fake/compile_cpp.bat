set problem=fake

g++ -std=c++14 -O2 -Wl,--stack=536870912 -o "%problem%" "grader.cpp" "%problem%.cpp"
