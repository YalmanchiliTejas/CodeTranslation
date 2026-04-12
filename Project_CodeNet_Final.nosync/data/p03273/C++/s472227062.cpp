#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int H, W; cin >> H >> W;
  bool h[110] = {}, w[110] = {}; char S[H][W];
  rep(i, H){
    rep(j, W){
      cin >> S[i][j];
      if(S[i][j]=='#') {h[i]=true; w[j]=true;}
    }
  }
  rep(i, H){
    if(!(h[i])) continue;
    rep(j, W){
     if(!(w[j])) continue;
     cout << S[i][j];
    }
    cout << endl;
  }
}