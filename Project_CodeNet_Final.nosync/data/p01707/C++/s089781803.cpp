#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

const int mod=1000000007;



ll inv(ll a){
	ll n=mod-2;
	ll res=1;
	while(n){
		if(n&1) res=(res*a)%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res%mod;
}


ll dp[2010][2010];

int main(void){
	ll n,d,x;
	while(1){
		cin >> n >> d >> x;
		x--;
		
		if(n==0)
			break;
		
		dp[0][0]=1LL;

		for(int i=0;i<n;++i){
			for(int j=1;j<=n;++j){
				if(j-x-1>=0)
					dp[i+1][j]=(dp[i+1][j-1]+dp[i][j-1]-dp[i][j-x-1]+mod)%mod;
				else
					dp[i+1][j]=(dp[i+1][j-1]+dp[i][j-1])%mod;
			}
		}
		
		ll ans=0;
		ll com=1;
		for(ll i=1;i<=n;++i){
			ll dd=(d-(i-1)+mod)%mod;;
			com=com*dd%mod;
			com=com*inv(i)%mod;
			ans=(ans+com*dp[i][n]+mod)%mod;
		}
		cout << ans << endl;
	}
	return 0;
}