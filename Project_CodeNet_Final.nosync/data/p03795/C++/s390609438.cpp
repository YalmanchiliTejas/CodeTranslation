#include <iostream>
#include <string>
#include <cstdlib>

int main(){
std::string line;
std::getline(std::cin, line);
int N = atoi(line.c_str());

std::cout << 800*N-200*(N/15) << std::endl;

return 0;
}