#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
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
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに


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


// 10^18まではいけるようだが、10^19でオーバーフローする
// MODをつけたい場合もこれでもいい
// 繰り返し二乗法を使っているので O(logN) で計算できる
ll llpow(ll x, ll n){
  ll ans = 1;
  while (n > 0){
    if (n % 2 == 1) ans = ans * x % MOD;
    x = x * x % MOD;
    n /= 2; // n を右に1つビットシフト
  }
  return ans;
}

// --------- library end - //


int main(){

  string original_K = is();
  ll K_digits = original_K.size(); // Kの桁数

  // Kに0埋めをかけて10005桁にする
  string K(10005, '0');
  rep(i, K_digits){
    K[10004-i] = original_K[K_digits-1-i];
  }

  ll D = il();

  // dp[d][s][m] := 上からd桁目(0-idxd)まで見て、s=(0:exact|1:smaller)であるときの、m mod D であるような数の選び方の個数
  // 上の方の何桁かは番兵
  // 問題では 1以上K以下 だが、この段階では 遷移の都合上、0 を含むことにする
  vector<vector<vector<ll> > > dp(10005, vector<vector<ll> >(2, vector<ll>(D, 0)));

  // 初期化
  dp[0][0][0] = 1; // 0を含むことにしているので、000... という取り方が1通りある

  // d から d+1 に配るDP
  rep(d, 10004){
    ll k_digit = K[d+1] - '0'; // Kのd+1桁目の数字
    if (d==10003){
      assert(d==10003);
    }

    // exact -> exact
    // Kのd+1桁目と同じ数字を選ぶしかない
    rep(m, D){
      dp[d+1][0][(m+k_digit)%D] += dp[d][0][m];
      dp[d+1][0][(m+k_digit)%D] %= MOD;
    }

    // exact -> smaller
    // k_digit==0 だと構成できない
    // k_digit>=1 の場合は、0~k_digit-1 を選べる
    rep(i, k_digit){
      // d桁目にiを選んだとする
      rep(m, D){
        dp[d+1][1][(m+i)%D] += dp[d][0][m];
        dp[d+1][1][(m+i)%D] %= MOD;
      }
    }


    // smaller -> smaller
    // 0~9 の何を選んでもいい
    rep(i, 10){
      // d+1桁目にiを選んだとする
      rep(m, D){
        dp[d+1][1][(m+i)%D] += dp[d][1][m];
        dp[d+1][1][(m+i)%D] %= MOD;
      }
    }

  }

  ll ans = (dp[10004][1][0] + dp[10004][0][0] - 1) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;


}