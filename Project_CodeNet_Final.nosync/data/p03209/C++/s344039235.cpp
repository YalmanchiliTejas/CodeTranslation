#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define rng(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef set<int> si;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef __int128_t lll;
typedef pair<lll,lll> plll;
typedef vector<lll> vlll;
template<typename T>string join(vector<T>&v){stringstream s;FOR(i,0,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0;return gcd(a,b,x,y);}
ll modpow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isprime(ll n){if(n<2)return 0;if(!(n%2))return !(n-2);lll d=n-1,t,y;while(!(d%2))d>>=1;vl al={2,325,9375,28178,450775,9780504,1795265022};for(ll a:al){if(n<=a)break;t=d,y=modpow(a,t,n);while(t!=n-1&&y!=1&&y!=n-1)y=y*y%n,t<<=1;if(y!=n-1&&!(t%2))return 0;}return 1;}
void dout(double d){printf("%.12f\n",d);}
void YN(bool z){cout<<(z?"YES\n":"NO\n");}
void Yn(bool z){cout<<(z?"Yes\n":"No\n");}
void yn(bool z){cout<<(z?"yes\n":"no\n");}
const mt19937 rnd(unsigned(1357986421));
const int iinf = 1e9+6;
const ll linf = 1e18;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-10;

const int N = 55;
int n;
ll X;
ll search(ll l, ll x){
  if(x < 1) return 0;
  if(x >= (1ll<<(l+2))-3) return (1ll<<(l+1))-1;
  ll ret = 0;
  x -= 1;
  ret += search(l-1, x);
  x -= (1ll<<(l+1))-3;
  if(x > 0) ret++;
  x -= 1;
  ret += search(l-1, x);
  return ret;
}

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> X;
  cout << search(n, X) << endl;
  return 0;
}