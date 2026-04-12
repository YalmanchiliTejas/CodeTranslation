#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<int> H;
  rep(i,N){
    int h;
    cin >> h;
    H.push_back(h);
  }

  int ret = 0;
  rep(i,N){
    bool flg = true;
    rep(j,i){
      if(H[j] > H[i]) flg = false;
    }
    if(flg) ret++;
  }

  cout << ret << endl;
  
  return 0;
}
