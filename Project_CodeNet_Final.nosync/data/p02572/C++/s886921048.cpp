//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define MEM(x) memset(x,0,sizeof(x))
#define vc vector<int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define inf 0x3f3f3f3f
#define t_case int tt; cin>>tt; while (tt--)
#define lnginf 9223372036854775807
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define For(i,j,k) for (int i=(int)(j);i<(int)(k);i++)
#define rFor(i,j,k) for (int i=(int)(k-1);i>=(int)(j);i--)
#define ins insert
#define in(x); { for (auto &i : x) cin >> i; }
#define out(x); { for (auto i : x) cout<<i<<' ' ; }
#define pi  pair<int,int>
#define ti tuple<int,int,int>
#define PI 3.14159265359
#define des(x) setprecision(x)
const long long LL_INF = (long long) 2e18 + 5;
using namespace std;
//void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int N=3e5+10,mod=1e9+7;
int sum(int a,int b){
  int s=a+b;
  if(s>=mod)s-=mod;
  return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

void solve(){
  int n; cin>>n;
  vector<int> v(n),pre(n);
  For(i,0,n){
    cin>>v[i];
    if(!i)pre[i]=v[i];
    else pre[i]=sum(pre[i-1],v[i]);
  }
  int s=0;
  For(i,0,n-1){
    s=sum(s,mult(v[i],sub(pre[n-1],pre[i])));
  }
  cout<<s<<'\n';
  
}
int32_t main() {

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   fastio
   //t_case
    solve();



}