#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
  int N;
  string S;
  int K;
  cin>>N>>S>>K;
  char A=S[K-1];
  rep(i,N){
      if(S[i]!=A){
          S[i]='*';
      }
  }
  cout<<S<<endl;
}
