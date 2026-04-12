#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N){
    cin >> H[i];
  }

  int maxh = 0, ans=0;
  REP(i, N){
    if(maxh <= H[i]){
      ans++;
      maxh = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}