#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define rep(i, a, b) for (auto (i) = (a); (i) < (b); (i)++)
#define rrep(i, a, b) for (auto (i) = (a); (i) > (b); (i)--)

#define aim_cpo do{ios::sync_with_stdio(false);\
cin.tie(nullptr);cout.precision(12);cout<<fixed;}while(0)

#define LOCAL_INPUT do{FILE *stream1;\
stream1=freopen("/Users/aim_cpo/CLionProjects/competitive/in.txt","r",stdin);\
if(stream1==nullptr)return 0;}while(0)
#define LOCAL_OUTPUT do{FILE *stream2;\
stream2 = freopen("out.txt", "w", stdout);\
if (stream2 == nullptr) return 0;}while(0)

#ifdef LOCAL_DEFINE
#define show(x) cerr << #x << " = " << (x) << endl
#define showV(v, n) do{\
for(int _i_t_e_=0; _i_t_e_<(n);_i_t_e_++)\
cerr<<"("<<_i_t_e_<<" = "<<(v)[_i_t_e_]<<") ";\
cerr<<endl;}while(0)
#define showA(a, n) do{\
for(int _i_t_e_=0;_i_t_e_<(n);_i_t_e_++)\
cerr<<"("<<_i_t_e_<<" = "<<(a)[_i_t_e_]<<") ";\
cerr<<endl;}while(0)
#define showA2(a, n, m) do{\
for(int _i_t_e_=0;_i_t_e_<(n);_i_t_e_++){\
for(int _i_t_e_2=0;_i_t_e_2<(m);_i_t_e_2++){\
cerr<<"("<<_i_t_e_<<", "<<_i_t_e_2<<" = "<<(a)[_i_t_e_][_i_t_e_2]<<") ";\
}cerr<<endl;}cerr<<endl;}while(0)
#else
#define show(x)
#define showV(v, n)
#define showA(a, n)
#define showA2(a, n, m)
#endif

typedef long long ll;
typedef unsigned long long ull;

constexpr const int INT_INF=0x3f3f3f3f; //1061109567
constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f; //4557430888798830399

template <typename T> bool chmin(T &a, T b){return a>b?(a=b,true):false;}
template <typename T> bool chmax(T &a, T b){return a<b?(a=b,true):false;}
template <typename T> void ln(T i, T n){cout<<(i==n-1?"\n":" ");}
template <typename T, typename S>
ostream &operator<<(ostream &out,const pair<T, S> &pair1){
  out<<'('<<pair1.fi<<", "<<pair1.se<<')';return out;}

// INT
#define GCD(a, b) __gcd(a, b)
template <typename T> T LCM(T a, T b) {return a / GCD(a, b) * b;}
template <typename T> T EXTGCD(T a, T b, T& x, T& y) {
  T d = a;
  if (b != 0) {d=EXTGCD(b,a%b,y,x);y-=(a/b)*x;}
  else x=1,y=0;
  return d;
}
template <typename T> bool is_prime(T a) {
  for(int i=2;i*i<=a;i++)if(a%i==0)return 1;
  return 0;
}

// MOD
ll MOD = 1000000000L + 7L;
#define add(a, b) ((a % MOD) + (b % MOD)) % MOD
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define sub(a, b) ((a % MOD) + MOD - (b % MOD)) % MOD
template <typename T> T mod_inverse(T a, T mod, bool prime){ // if mod is prime, "prime" is true.
  if(prime){
    T tmp=mod-2,now=a,res=1;while(tmp){if(tmp&1)res=mul(res,now);now=mul(now,now);tmp>>=1;}
    return res;
  }else{T x,y;EXTGCD(a,mod,x,y);return (mod+x%mod)%mod;}
}
#define divide(a, b) ((a % MOD) * (mod_inverse(b, MOD, true))) % MOD

//LLの数値をつかう時は最後にLをつける癖をつけよう
//
//  ┏┓┏┓　┓　┏┓
//  ┏┛┃┃　┃　┗┫
//  ┗┛┗┛　┻　┗┛
//
//   謹┃賀┃新┃年┃
//   ━┛━┛━┛━┛
//WWWWWWWWWWWWWWWWWWWWWW

int n, a, b, c, d;
ll dp[1001][1001];
ll p[1001][1001];
ll f[1001];
ll finv[1001];
ll pinv[1001];

ll pow1(ll i, ll j) {
  ll res = 1;
  ll now = i;
  while (j) {
    if (j & 1) res = mul(res, now);
    j >>= 1;
    now = mul(now, now);
  }
  return res;
}

int main() {
  aim_cpo; // インタラクティブのときは消すように.
#ifdef LOCAL_DEFINE
  LOCAL_INPUT; // インタラクティブのときは消すように.
//  LOCAL_OUTPUT; // ファイルに出力したいときのみ
  show(MOD);
#endif
  cin >> n >> a >> b >> c >> d;
  rep(i, 1, n + 1) {
    ll now = i;
    p[i][0] = 1;
    rep(j, 1, i + 1) {
      p[i][j] = mul(p[i][j - 1], now);
      now--;
    }
  }
  f[0] = 1;
  rep(i, 1, n + 1) {
    f[i] = mul(f[i - 1], i);
  }
  rep(i, 0, n + 1) {
    finv[i] = mod_inverse(f[i], MOD, true);
  }
  dp[0][0] = 1;
  rep(i, 0, b - a + 1) {
    rep(j, 0, 1001) {
      pinv[j] = mod_inverse(pow1(f[a + i], j), MOD, true);
    }
    rep(j, 0, n + 1) {
      if (dp[i][j] == 0) continue;
      dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
      rep(k, c, d + 1) {
        if (j + k * (a + i) > n) break;
        dp[i + 1][j + k * (a + i)] = add(dp[i + 1][j + k * (a + i)], mul(mul(mul(dp[i][j], p[n - j][k * (a + i)]), finv[k]), pinv[k]));
      }
    }
  }
  //showA2(dp, b - a + 2, n + 1);
  cout << dp[b - a + 1][n] << endl;
#ifdef  LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
  return 0;
}