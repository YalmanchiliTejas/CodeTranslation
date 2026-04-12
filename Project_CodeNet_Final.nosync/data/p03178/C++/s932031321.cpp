
// Problem : S - Digit Sum
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_s
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")  //Optimization flags
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
#define binf (ll)1000000000*(ll)1000000000
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
#define all(a) a.begin(),a.end()
#define vl vector<ll>


/*#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}*/


//#define x ff
//#define y ss
#define pt(a) for(auto it:a)cout<<it<<" ";cout<<endl;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
using namespace std;

using namespace __gnu_pbds;
 
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> order_set;

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
    if (b & 1)res = res * a % m;
      a = a * a % m;
      b >>= 1;
  }
  return res;
}


ll kv;
ll t,n,x,y,h,k,z,p,q,w,d;
string s,s1,s2;
//vvl v;
//vl vis,d;

void solve(){
	cin>>s>>d;
	n=sz(s);
	
	vvl dp2(n,vl(d,0));
	
	x=s[0]-'0';
	for(ll i=0;i<x;i++){
		dp2[0][i%d]++;
	}
	x%=d;
	for(ll i=1;i<n;i++){
		
		fo(j,d){
			for(ll l=0;l<10;l++){
				dp2[i][j]+=dp2[i-1][(j-l+d*10)%d];
				dp2[i][j]%=mod;
			}
			
		}
		for(ll l=0;l<s[i]-'0';l++){
				dp2[i][(x+l)%d]++;dp2[i][(x+l)%d]%=mod;
			}
		x+=s[i]-'0';x%=d;
	}
	
	kv=(dp2[n-1][0]+(x==0)-1+mod)%mod;
	cout<<kv<<el;
	
}

int main() {
    IOS;
    //cin>>t;
    t=1;	
	fo(l,t){
		solve();
	}
    return 0;
}
