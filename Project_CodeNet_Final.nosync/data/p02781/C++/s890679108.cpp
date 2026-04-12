#include <bits/stdc++.h>
#define REP(i, n)     for(int i = 0;i < n;i++)
#define REPR(i, n)    for(int i = n;i >= 0;i--)
#define FOR(i, m, n)  for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.begin(), v.end(),greater<int>());
#define ALL(X) (X).begin(),(X).end()
#define INF 99999999
#define M_PI 3.14159265358979323846
#define MOD 1000000007

#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

#ifdef __LOCAL
    #include <filesystem>
    namespace fs = std::filesystem;
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 0};
int dy[]={0, 1, 0, -1, 0};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);
const int NIL = -1;
static mt19937 _g(time(nullptr));
 
std::string pad(int num){ char buffer[4]; std::snprintf(buffer, sizeof(buffer), "%03d", num); return buffer;}
inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) os << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

// ナップサック問題なんだけど
// ふつうのナップサックと異なる。


ll N,K;
string S;

void input(){
  #ifdef __LOCAL
      fs::path p = __FILE__;
      fs::path input,output;
      input = output = p.parent_path();
      input += string("/input/") + string(p.stem()) + string(".txt");
      output += string("/output/") + string(p.stem()) + string(".txt");
      freopen(input.c_str(), "r", stdin);
      freopen(output.c_str(), "w", stdout);
  #endif

  fast_io();
  cin >> S >> K;
}


ll fact_db[110];

ll fact(ll x){
  if(fact_db[x]) return fact_db[x];
  if(x==0||x==1) return fact_db[x] = 1LL;
  return fact_db[x] = x*fact(x-1);
}

ll combi(ll n, ll k){
  if(k==0) return 1LL;
  if(k==1) return n;
  if(k==2) return n*(n-1)/2;
  if(k==3) return n*(n-1)*(n-2)/6;
  return fact(n)/fact(n-k)/fact(k);
}


// ll calc(ll N, ll K){
//   if(K==0) return 1;
//   // if(N==0) return 1;
//   string s = to_string(N);
//   int m = s.size()-1;
//   ll res=0;
//   res += combi(m,K)*pow(9,K);
//   if(s[0]>='2') res += combi(m,K-1)*pow(9,K-1)*(s[0]-'0'-1);
//   s[0] = '0';
//   ll n = stoi(s);
//   res += calc(n,K-1);
//   return res;
// }

ll calc(string &s, ll K){
  if(K==0) return 1;
  if(s[0]=='0'){
    s.erase(0,1);
    return calc(s,K);
  }
  if(s=="") return 0;
  // if(stoi(s)==0) return 1;
  // string s=t;
  // if(N==0) return 1;
  int m = s.size()-1;
  ll res=0;
  res += combi(m,K)*pow(9,K);
  if(s[0]>='2') res += combi(m,K-1)*pow(9,K-1)*(s[0]-'0'-1);
  s.erase(0,1);
  // ll n = stoi(s);
  res += calc(s,K-1);
  return res;
}


int solve(){
  input();
  cout << calc(S,K) << endl;
  return 0;
}

ll dp[102][2][5];

int dpsolve(){
  input();
  memset(dp,0,sizeof(dp));
  dp[0][0][0] = 1;

  REP(i,S.size()) REP(j,2) REP(l,K+1){
    int lim = j ? 9:(S[i]-'0');
    REP(d,lim+1){
      dp[i+1][j||(d<lim)][l+(d!=0)] += dp[i][j][l];
    }
  }
  ll ans = 0;
  REP(j, 2) ans += dp[S.size()][j][K];
  cout << ans << endl;

  return 0;  
}


int main()
{
  dpsolve();
  return 0;
}
