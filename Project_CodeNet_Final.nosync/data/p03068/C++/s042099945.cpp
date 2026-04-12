#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N,K;
  string S;
  cin>>N;
  cin>>S;
  cin>>K;
  char t;
  t = S[K-1];
  for (int i = 0; i < N; i++) {
    if (S[i] != t) S[i] = '*';
  }
  cout<<S<<endl;
  return 0;
}