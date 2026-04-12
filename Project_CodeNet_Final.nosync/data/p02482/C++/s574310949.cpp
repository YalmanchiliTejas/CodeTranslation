#include<iostream>

int main(){
int b,a;
std::cin>>a>>b;
if(a<b) std::cout<<"a < b"<<std::endl;
else if(a==b) std::cout<<"a == b"<<std::endl;
else if(a>b) std::cout<<"a > b"<<std::endl;
return 0;
}