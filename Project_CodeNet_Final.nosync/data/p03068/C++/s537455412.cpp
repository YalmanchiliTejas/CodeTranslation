#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(void){
  int N, K;
  string S;
  cin >> N >> S >> K;
  for(int i = 0; i < N; i ++){
    if(S[i] != S[K-1]){ S.replace(i, 1, "*");
    }
  }
  cout << S << endl;
  return 0;
}
