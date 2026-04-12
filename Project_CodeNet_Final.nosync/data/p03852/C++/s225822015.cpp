#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

int main(){
    char ch;
    std::cin>>ch;

    std::string s = "aeiou";
    std::string ans;
    if(s.find(ch) == std::string::npos){
        ans = "consonant";
    }else{
        ans = "vowel";
    }
    std::cout<<ans<<std::endl;
    return 0;
}