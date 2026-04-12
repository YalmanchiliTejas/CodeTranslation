#include <iostream>
int main(){int x,y,z,a=0;std::cin>>x>>y>>z;while(a*y+(a+1)*z<=x)++a;std::cout<<a-1<<"\n";}