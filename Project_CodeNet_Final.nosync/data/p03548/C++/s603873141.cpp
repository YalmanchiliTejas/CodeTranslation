#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int x,y,z,count = 0;
    std::cin >> x >> y >> z;
    x = x - 2 * z;
    if(x >= y){
        x = x - y;
        count++;
    }
    count = count + (x / (y + z));
    std::cout <<count<<std::endl;
    return 0;
}
