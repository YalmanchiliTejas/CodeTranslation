#include <iostream>

int r,g,b;

int main() {

    std::cin>>r>>g>>b;

    if((r*100+g*10+b)%4==0)
        std::cout<<"YES"<<std::endl;
    else
        std::cout<<"NO"<<std::endl;

    return 0;
}