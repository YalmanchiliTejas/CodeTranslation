#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll pcnt[55];
ll cnt[55];

ll calc(int N, ll X){
  if(N < 0 || X < 0) return 0;
  if(N == 0) return 1;
  if(X+1 == cnt[N]) return pcnt[N];
  ll middle = cnt[N]/2;

  if(middle <= X){
    return pcnt[N-1] + 1 + calc(N-1, X-middle-1);
  }else{
    return calc(N-1, X-1);
  }
}


int main(){
  int N;
  ll X;
  cin >> N >> X;

  pcnt[0] = 1;
  cnt[0] = 1;
  rep(i,50){
    pcnt[i+1] = 2*pcnt[i] + 1;
    cnt[i+1] = 2*cnt[i] + 3;
  }

  cout << calc(N, X-1) << endl;
  
  return 0;
}


