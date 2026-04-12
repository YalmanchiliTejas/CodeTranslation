#include <iostream>
#include <string>

int main() {

    std::string str;

    std::cin>>str;

    if(str.find("AC")!=std::string::npos)
        std::cout<<"Yes"<<std::endl;
    else
        std::cout<<"No"<<std::endl;

    return 0;
}