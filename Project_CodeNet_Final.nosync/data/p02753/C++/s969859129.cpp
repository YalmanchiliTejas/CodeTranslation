#include <iostream>
#include <string>
int main(){
    std::string str;
    std::cin >>str;
    if(str=="AAA"||str=="BBB"){
        std::cout<<"No";
    }else{
        std::cout<<"Yes";
    }
}