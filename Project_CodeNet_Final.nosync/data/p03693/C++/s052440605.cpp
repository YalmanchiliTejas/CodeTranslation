#include <iostream>
int main(){
int x,y,z;
std::cin >> x >> y >> z;
if((y*10+z)%4==0)
std::cout << "YES" << std::endl;
else
std::cout << "NO" << std::endl;
}