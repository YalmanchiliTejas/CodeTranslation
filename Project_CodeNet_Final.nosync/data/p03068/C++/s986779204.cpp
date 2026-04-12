#include <iostream>

using namespace std;

int main(){
  int N,K;
  char S[N];
  cin >> N >> S >> K;
  char a = S[K-1];
  for(int i = 0;i<N;i++){
    if (S[i] != a){
      S[i] = '*';
    }
  }
  std::cout << S << std::endl;
  return 0;
}
