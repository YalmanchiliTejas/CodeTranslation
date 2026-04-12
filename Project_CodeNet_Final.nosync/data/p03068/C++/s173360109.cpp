#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
#define INF 1e9
typedef long long ll;

int main(void){
  int i,N,K;
  string S;
  cin >> N >> S >> K;
  K--;
  REP(i,N){
    if(S[i]!=S[K])cout << '*';
    else cout << S[i];
  }
  cout << endl;
  return 0;
}
