#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> S >> K;
  char p = S[K - 1];
  for (int i = 0; i < N; i++){
    if (p != S[i]) S[i] = '*';
  }
  cout << S << endl;
}
  