#include <iostream>

int main()
{
  int N;
  std::string S;
  int K;
  std::cin >> N >> S >> K;
  char P;
  P=S[K-1];
  for(int i=0; i<N; i++){
   	if(S[i] != P){
      std::cout << "*";
    }else{
     std::cout << S[i];
    }
  }
  std::cout << std::endl;
  return 0;
}