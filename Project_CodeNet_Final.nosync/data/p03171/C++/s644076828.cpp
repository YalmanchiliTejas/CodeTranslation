#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define forn(low,high,i) for(i = low;i < high;i++)
#define forrev(high,low,i) for(i = high; i >= low;i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define line cout << __LINE__;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define prvp(a) for(auto x : a) cout << "{" << x.ff << ',' << x.ss << "}";cout << '\n';
#define decimal_digits cout << fixed << setprecision(15);
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int bit32 = log2(inf) + 3;
const int bit64 = log2(INF) + 3;

inline int add(int a, int b){a += b; if(a >= mod) a -= mod; return a;}
inline int sub(int a, int b){a -= b; if(a < 0) a += mod; return a;}
inline int mul(int a, int b){return (int)((long long) a * b % mod);}
inline int modexpo(int a, int b){int res = 1; while(b > 0){ if(b & 1) res = mul(res, a); a = mul(a, a); b /= 2;} return res;}
inline int divide(int a, int b){ return mul(a, modexpo(b, mod - 2));}

clock_t time_p = clock();

void ktj(){
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (float)(time_p)/CLOCKS_PER_SEC << "\n";
}

void pre(){ // Reset each global variable (esp. for graphs)
  
}

const int N = 3000 + 1;
int a[N], n;
ll dp[N][N][2];

ll solve(int l, int r, int p){
  if(l > r)
    return 0;
  ll &ans = dp[l][r][p];
  if(~ans)
    return ans;
  if(p){
    ans = max(a[l] + solve(l + 1, r, 1 - p), a[r] + solve(l, r - 1, 1 - p));
  }else{
    ans = min(-a[l] + solve(l + 1, r, 1 - p), -a[r] + solve(l, r - 1, 1 - p));
  }
  return ans;
}

void solve(){
  cin >> n;
  int i, j, k;
  memset(dp, -1, sizeof dp);
  for(i = 1; i <= n; i++){
    cin >> a[i];
  }
  cout << solve(1, n, 1) << '\n';
}

int main(){
  fastio

  pre();

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  ktj();
}
