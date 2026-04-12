#include <iostream>
 
int main() {
int x=0;
int y=0;
int N;
std::cin >> N;
 
x = 800*N;
int z;
z = N/15;
y = z*200;
 
std::cout << (x-y) << std::endl;
return 0;
}