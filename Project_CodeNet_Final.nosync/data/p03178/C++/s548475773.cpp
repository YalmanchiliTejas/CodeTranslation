#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define all(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define bit(n) (1LL<<(n))
#define randInt(l,r) (uniform_int_distribution<ll>(l,r)(rnd))
#define randDouble(l,r) (uniform_real_distribution<double>(l,r)(rnd))

typedef long long ll;
typedef __int128_t lll;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0;return gcd(a,b,x,y);}
ll modPow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isPrime(ll n){if(n<2||n%2==0)return n==2;lll t=n-1,d=t/(t&-t);for(lll a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){for(t=d,a=modPow(a,t,n);t!=n-1&&a!=1&&a!=n-1;a=a*a%n,t=t*2%n);if(a!=n-1&&t%2==0)return 0;}return 1;}
void dout(double d){printf("%.12f\n",d);}
const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7;
const double PI = acos(-1);
const double EPS = 1e-10;
static random_device rd;
static mt19937 rnd(rd());

const int N = 1e4+5;
string k;
int d, n;
ll full[N][100];
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> k >> d;
  n = sz(k);
  full[0][0] = 1;
  FOR(i, 1, N)FOR(j, 0, d)FOR(k, 0, 10) full[i][(j+k)%d] = (full[i][(j+k)%d] + full[i-1][j]) % MOD;
  int s = 0;
  ll ans = 0;
  FOR(i, 0, n){
    int c = k[i]-'0';
    FOR(j, 0, 10){
      if(j<c){
        ans = (ans + full[n-i-1][((-s-j)%d+d)%d]) % MOD;
      }else if(j==c){
        s += c;
      }else{
        break;
      }
    }
  }
  if(s%d) ans--;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << endl;
}