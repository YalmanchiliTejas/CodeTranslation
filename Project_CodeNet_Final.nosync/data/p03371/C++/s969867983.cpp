#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）
 
#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに
 
//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
// ----- template end ---- //
 
// ------- library ------- //



// ----- library end ----- //



int main() {

  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  //0~10^5全探索
  ll min = LINF;
  ll zero = 0;
  rep(i, pow(10,5)+1){
    chmin(min, i*2*C + A*max(X-i, zero) + B*max(Y-i, zero));
  }

  cout << min << endl;

// -- main() end -- //
}


 