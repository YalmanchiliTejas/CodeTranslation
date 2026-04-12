#include <iostream>
#include <string>
int main()
{
int N;
std::string S;
int K;
 
std::cin >> N;
std::cin >> S;
std::cin >> K;
 
for (int i = 0; i < N; ++i){
    if (S[i] == S[K - 1]) {
       std::cout << S[K - 1] ;
       } else {
       std::cout << "*";
       }
}
 
return 0;
}