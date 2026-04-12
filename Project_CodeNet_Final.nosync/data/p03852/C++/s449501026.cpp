#include <iostream>
#include <string>
int main(){
std::string S;
std::cin >> S;
if(S=="a" || S=="i" || S=="u" || S=="e" ||S=="o")
std::cout << "vowel" << std::endl;
else
std::cout << "consonant" <<std::endl;
}