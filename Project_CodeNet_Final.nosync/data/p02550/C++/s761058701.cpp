#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define b_e(a) a.begin(),a.end() //sort(b_e(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //

// #include <atcoder/all>
// using namespace atcoder;



// --------- library end - //



int main(){

  ll N, X, M;
  cin >> N >> X >> M;
  
  // modint ans(X);
  // ans.set_mod(M);

  // ans = ans.pow(N*2);
  // ans -= 1;

  // // ans *= X;
  // // ans *= X;

  // ll div = (X * X % M - 1);
  // if (div < 0) div += M;

  // ans /= div;

  // cout << ans.val() << endk;

  // dp[i] := <a[k] = i だった時の a[k+1] の値（ループの起点となる値）, old_xが前回出た箇所（ループの起点）>
  vector<pll> dp(100001, m_p(-1, 0));

  ll ans = X;
  ll width = -1;

  rep(i, N-1){
    if (dp[X].first != -1){
      // ループした
      ans -= X;

      // 起点の座標
      ll start = dp[X].second;

      // ループの幅
      ll width = i - start;

      // ここからは 残り区間の幅 ÷ ループの幅) * 区間の総和 + (余り) だけ　進む
      
      // まずは区間の総和を計算
      ll tmpsum = X;
      ll tmpx = X;
      rep(j, width-1){
        ll newtmpx = tmpx * tmpx % M;
        tmpsum += newtmpx;
        tmpx = newtmpx;
      }
      // このときtmpx は ループ終了の1つ前

      // 残り区間の幅
      ll nokori = N - 1 - (i - 1);
      ans += (nokori / width) * tmpsum;

      // 余り
      nokori %= width;
      if (nokori != 0) {
        rep (j, nokori){
          ll newtmpx = tmpx * tmpx % M;
          ans += newtmpx;
          tmpx = newtmpx;
        }
      }

      cout << ans << endk;
      return 0;

    }
    else{
      ll newx = X * X % M;
      dp[X] = m_p(newx, i);
      ans += newx;
      X = newx;
        
      if (X == 0){
        cout << ans << endk;
        return 0;
      }
    }
  }

  cout << ans << endk;



  

}

