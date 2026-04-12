#include <iostream>
int main(){
 char c;
 std::cin >> c;
 if (c==97||c==101||c==105||c==111||c==117){
     std::cout << "vowel" << std::endl;
     }
 else {
     std::cout << "consonant" << std::endl;
 }
}