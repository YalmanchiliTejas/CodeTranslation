#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define pr(...) GET_MACRO(__VA_ARGS__,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)
#define pr1(a) (#a)<<"="<<(a)
#define pr2(a,b) pr1(a)<<", "<<pr1(b)
#define pr3(a,b,c) pr2(a,b)<<", "<<pr1(c)
#define pr4(a,b,c,d) pr3(a,b,c)<<", "<<pr1(d)
#define pr5(a,b,c,d,e) pr4(a,b,c,d)<<", "<<pr1(e)
#define int long long
#define double long double
using namespace std;
const int N = 1010;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n){
    if(n%2) res=res*x%mod;
    x=x*x%mod;
    n/=2;
  }
  return res;
}

ll factorial(int i){
  static vector<ll> k(1e6);
  if(!k[0]){k[0]=1;for(int i=1;i<(int)k.size();i++)k[i]=i*k[i-1]%mod;}
  return k[i];
}

ll nCr(ll n,ll r){
  ll a = mod_pow( factorial(r) * factorial(n-r) % mod ,mod-2);
  return factorial(n) * a % mod;
}


int calc(int n,int i,int f){
  int a = factorial(n);
  int b = factorial(n-i*f);
  int c = mod_pow(factorial(i),f);
  return (a * mod_pow(b,mod-2)%mod) * mod_pow(c,mod-2) % mod;
}

int A,B,C,D;
int dfs(int n,int i){
  static int mem[N][N],used[N][N]={};
  if(n == 0) return 1;
  if(i > B) return 0;
  if(used[n][i]++) return mem[n][i];
  int res = dfs(n,i+1);
  for(int F=C;F<=D;F++){
    if(n - i * F < 0) break;
    int r = calc(n,i,F) * mod_pow(factorial(F),mod-2) % mod;
    res = (res + dfs(n-i*F,i+1) * r % mod) % mod;
  }
  return mem[n][i] = res;
}

signed main(){
  int n;
  cin>>n;
  cin>>A>>B>>C>>D;

  int ans = dfs(n,A);
  cout<<ans<<endl;
  
  return 0;
}
