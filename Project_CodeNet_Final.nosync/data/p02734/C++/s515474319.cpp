#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define ALL(x) (x).begin(), (x).end()
LL POW(LL a,LL p,LL M){ if(!p) return 1LL;LL T = POW(a,p/2,M);T = T*T%M; if(p&1) T=T*(a%M)%M; return T; }
LL SQRT(LL a) { LL b = (LL)sqrtl(((double)a)+0.5); while(b*b<a) ++b; while(b*b>a) --b; return (b*b==a)?b:-1; }
//endl
//<------------------------edits---------------------------------------------->
const LL MOD = 998244353;
// #define LOCAL LDD
// #define int LL

const int N = 3002;
LL dp[N][N];

LL solve(int ps,int lft,vector<int>& a){
  if(lft<0) return 0; 
  if(ps==a.size()){
    if(lft==0) return 1;
    else return 0;
  }
  if(dp[ps][lft]!=-1) return dp[ps][lft];
  LL ans = 0;
  ans += solve(ps+1,lft-a[ps],a);
  ans += solve(ps+1,lft,a);
  if(lft==0) ans += 1;
  ans %= MOD;
  return dp[ps][lft] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
#endif
  memset(dp,-1,sizeof(dp));
  int n,s;cin >> n >> s;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  LL ans = 0;
  for(int i=0;i<n;i++){
    ans += solve(i,s,a);
  }
  ans %= MOD;
  cout << ans << endl;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}