#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<pll> vpl;
typedef vector<int> vi;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0 ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
 
}

const int MAXN = 200100;
int suf[MAXN][2];
int pre[MAXN][2];
int pulo[MAXN];
int a[MAXN];
int dp[MAXN][3];
bool vis[MAXN][3];
  int n;
int solve(int id,int pulos){
  if(id>n){
    if(pulos!=2)return -1e15;
    return 0;
  }
  int &x = dp[id][pulos];
  if(vis[id][pulos])return x;
  vis[id][pulos] = 1;
 
  x=0;

  x = a[id] + solve(id+2,pulos);
  if(id+3<=n and pulos<2){
    x = max(x,a[id] + solve(id+3,pulos+1));
  }
  return x;
}

int32_t main(){
  fastio;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    pre[i][i%2]=(i>=2?pre[i-2][i%2]:0) + a[i];
  }

  for(int i=0;i<MAXN;i++){
    for(int j=0;j<3;j++){
      vis[i][j]= 0;
    }
  }
  if(n%2==0){
    int best = solve(1,2);
    best = max(best,solve(2,2));
    best = max(best,solve(1,1));
      cout<<best<<endl;
    return 0;
  }else{
    int best = max(solve(1,0),solve(2,1));
    best = max(best,solve(3,2));
    best = max(best,solve(1,1));
    if(n==3){
      best = max({a[1],a[2],a[3]});
      
    }
    cout<<best<<endl;
    return 0;
  }

  // Math -> gcd it all // chack MAXN // check ll
  //did you check N=1? Did you mix up N,M?
}