
#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#define pb push_back
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);
#define ll long long int
#define ld long double
#define el '\n'
#define El '\n'
#define PI (ld)3.141592653589793238462643383279502884197169399375105820974944
#define inf (ll)1000000000
#define mod (ll)1000000007
#define mod1 (ll)998244353
#define fo(i, n) for (long long i = 0; i < n; i++)
#define pll pair<ll, ll>
#define ml map<ll,ll>
#define vpl vector<pll>
#define vvl vector<vector<ll> >
#define vvpl vector< vector<pll> >
#define ff first
#define ss second
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< ll,vl ,greater< ll > >
#define mem(a,b) memset(a,b,sizeof(a));
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define sz(a) (ll)a.size()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define vl vector<ll>
//#define x ff
//#define y ss
#define pt(a) for(auto it:a)cout<<it<<" ";cout<<endl;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
using namespace std;

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << t<<" "; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << v.first << " " << v.second ; }

double gcd(double a, double b) { return a < 0.01 ? b : gcd(fmod(b, a), a); }

long long bpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)

      res = res * a % m;
      a = a * a % m;
      b >>= 1;
  }
  return res;
}


ll kv;
ll t,n,x,y,h,k,z,p,q,w,r;
string s,s1,s2;
vl v,a;
//vl vis,d;
ll dp[4000][4000];
ll sg(int x,int y){
    if(dp[x][y]!=inf*inf)return dp[x][y];
    if(x==y)return v[x];
    dp[x][y]=a[y+1]-a[x]-min(sg(x+1,y),sg(x,y-1));
    //cout<<x<<" "<<y<<" "<<dp[x][y]<<el;
    return dp[x][y];
}

int main() {
    IOS;
    cin>>n;
    v.resize(n);cin>>v;
    fo(i,4000)fo(j,4000)dp[i][j]=inf*inf;
    a.assign(n+1,0);
    fo(i,n)a[i+1]=a[i]+v[i];
    fo(i,n)kv+=v[i];
    cout<<2*sg(0,n-1)-kv;
    return 0;
}

