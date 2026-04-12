#include <iostream>
#include <string>
int main()
{
    std::string str,a;
    std::cin >> str;
    int c = 0;
    bool result = false;
    for(char b : str){
        if(b == 'A'){
            if(str[c + 1] == 'C'){
                result = true;
            }
        }
        c++;
        if(c == str.size())break;
    }
    if(result){
        std::cout <<"Yes"<<std::endl;
    }else{
        std::cout <<"No"<<std::endl;
    }
    return 0;
}
