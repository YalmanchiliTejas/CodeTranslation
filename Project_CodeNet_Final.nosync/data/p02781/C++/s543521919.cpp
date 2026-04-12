#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

const int N = 110;

int dp[N][5][2];
  int n ;
  string s;
int solve(int id,int k,int f){
  if(k<0)return 0;
  if(id<0){
    if(k==0)return 1;
    return 0;
  }
  int &x = dp[id][k][f];
  if(x!=-1)return x;
  x=0;
  for(int i=0;i<10;i++){
    // coloca i aqui:
    if(i > s[id]-'0' and f==0)continue;
    int nf = f;
    if(i<s[id]-'0')nf=1;
    x+=solve(id-1,k-(i!=0?1:0),nf);
  }
  return x;
}

int32_t main(){
  fastio;
  cin>>s;
  reverse(s.begin(),s.end());
  int k;
  cin>>k;
  memset(dp,-1,sizeof(dp));
  n = s.size();
  cout << solve(n-1,k,0) << endl;
  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}