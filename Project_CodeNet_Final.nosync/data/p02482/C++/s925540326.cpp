#include <iostream>
using namespace std;
int main(void)
{
int a,b;
std::cin >> a >> b;
if(a < b) std::cout << "a < b" << std::endl;
else if(b < a) std::cout << "a > b" << std::endl;
else std::cout << "a == b" << std::endl;
return 0;
}