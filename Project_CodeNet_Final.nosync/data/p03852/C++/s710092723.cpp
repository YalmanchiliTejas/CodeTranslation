#include<iostream>
#include<string>
int main(){
    char c;
    std::string vowel = "aiueo";
    std::cin >> c;
   if(vowel.find(c) != std::string::npos)std::cout <<"vowel";
   else std::cout << "consonant";
}