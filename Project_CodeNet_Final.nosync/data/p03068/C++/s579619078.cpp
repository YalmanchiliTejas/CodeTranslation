#include<iostream>
using namespace std;
int main() {
  int N,K,i;
  char S[11];
  cin >> N >> S >> K;
  for(i=0;i<N;i++) {
    if(S[i] != S[K-1])S[i] = '*';
  }
  cout << S << endl;
}