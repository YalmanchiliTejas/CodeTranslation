#include <bits/stdc++.h>
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

inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) os << "[" << el.first << " " << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) os << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

int N;
vector<ll> A;

void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path p = __FILE__;
        fs::path input,output;
        input = output = p.parent_path();
        input += string("/input/") + string(p.stem()) + string(".txt");
        output += string("/output/") + string(p.stem()) + string(".txt");
        freopen(input.c_str(), "r", stdin);
        freopen(output.c_str(), "w", stdout);
    #endif
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      ll a;
      cin >> a;
      A.push_back(a);
    }
    
}

pll dp[3010][3010];
bool used[3010][3010];

pll dfs(int l, int r){
  if(used[l][r]) return dp[l][r];
  used[l][r] = true;
  pll ret={0,0};
  int k=(l+r);
  if(l==N-r) return ret;
  if(k>N) return dp[l][r] = ret;
  if(k%2==0) {
    pll tmp_l = dfs(l+1,r);
    tmp_l.first += A[l];
    pll tmp_r = dfs(l,r+1);
    tmp_r.first += A[N-1-r];
    if(tmp_l.first >= tmp_r.first) ret=tmp_l;
    else ret=tmp_r;
    }
  else{
    pll tmp_l = dfs(l+1,r);
    tmp_l.second += A[l];
    pll tmp_r = dfs(l,r+1);
    tmp_r.second += A[N-1-r];
    if(tmp_l.second >= tmp_r.second) ret=tmp_l;
    else ret=tmp_r;
    }
  return dp[l][r] = ret;
}

int solve(){
  // memset(dp,0,sizeof(dp));
  // for (int l = 0; l < N; l++)
  // {
  //   for (int r = 0; r < N; r++)
  //   {
  //     if((l+r)%2==0) dp[l][r] = (ll)1e18;
  //     else dp[l][r] = -(ll)1e18;
  //   }
  // }

  // for (int l = 0; l < N; l++)
  // {
  //   for (int r = 0; r < N; r++)
  //   {
  //     int i=(l+r);
  //     if(i>N) continue;
  //     if(i%2==0) {
  //       if(l) dp[l][r] = max(dp[l][r],dp[l-1][r]+A[l-1]);
  //       if(r) dp[l][r] = max(dp[l][r],dp[l][r-1]+A[N-r]);
  //       }
  //     else{
  //       if(l) dp[l][r] = min(dp[l][r],dp[l-1][r]-A[l-1]);
  //       if(r) dp[l][r] = min(dp[l][r],dp[l][r-1]-A[N-r]);
  //     }
  //   }
  // }
  // ll ans;
  // if(N%2==0) {
  //   ans = 1e18;
  //   for (int i = 0; i < N; i++)
  //   {
  //     ans = min(ans,dp[i][N-i]);
  //   }
    
  // }
  // else{
  //   ans = -1e18;
  //   for (int i = 0; i <= N; i++)
  //   {
  //     ans = max(ans,dp[i][N-i]);
  //   }
  // }
  // cout << ans << endl;
  auto r = dfs(0,0);
  DBG(r)
  cout << (r.first-r.second) << endl;
  return 0;
}

int main()
{
    input();
    solve();
    return 0;
}
