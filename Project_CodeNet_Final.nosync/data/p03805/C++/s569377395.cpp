#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define pcnt __builtin_popcount
#define show(x) cout<<#x<<" = "<<x<<endl;
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define fi first
#define se second
#define rng(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz(x) (int)(x).size()
#define mp make_pair

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
template<typename T>string join(vector<T>&v)
{stringstream s;FOR(i,0,sz(v))s<<' '<<v[i];return s.str().substr(1);}
ll gcd(ll a,ll b){if(a>b)swap(a,b);for(;a>0;b%=a,swap(a,b));return b;}
int modpow(ll a,ll n,int m){if(a==0)return a;ll p=1;for(;n>0;n/=2,a=a*a%m)if(n&1)p=p*a%m;return(int)p;}
void dout(double d){printf("%.12f\n",d);}

const int iinf = 1e9;
const ll linf = 1e18;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-10;
int n, m;
bool G[8][8];
ll memo[256][8];

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  FOR(i, 0, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = true;
    G[b][a] = true;
  }
  memo[1][0] = 1;
  FOR(i, 2, 1<<n)FOR(j, 0, n) if((1<<j)&i)FOR(k, 0, n) if(G[j][k]) memo[i][j] += memo[i-(1<<j)][k];
  ll ans = 0;
  FOR(i, 0, n) ans += memo[(1<<n)-1][i];
  cout << ans << endl;
  return 0;
}
