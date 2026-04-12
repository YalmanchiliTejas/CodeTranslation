#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  string S; cin >>S;
  int K; cin >>K;
  char a=S[K-1];
  rep(i,0,N) {
    if (S[i]!=a) {
      S[i]='*';
    }
  }
  cout <<S <<endl;
  return 0;
}
