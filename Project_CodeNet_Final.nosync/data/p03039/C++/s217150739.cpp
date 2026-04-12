#include<bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<vi > vvi;
typedef std::vector<vll > vvll;
typedef std::pair<int,int> ii;
typedef std::pair< ll, ll > lp;
typedef std::vector<ii> vii;
typedef std::vector<vii > vvii;

#define pb emplace_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define mp make_pair
#define ub(a,b) upper_bound(all(a),b)
#define lb(a,b) lower_bound(all(a),b)
#define bs(a,b) binary_search(all(a),b)
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<"\n";cout<<endl
#define ff first
#define ss second
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define rep(i,n) F(i,0,n-1)
#define clr(a) (a).clear()
#define rz resize
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin() ,(a).rend()
#define endl '\n'

#define mod 1000000007

ll add(ll a, ll b){return (a%mod + b%mod)%mod;}
ll sub(ll a , ll b){return (a%mod - b%mod + mod)%mod;}
ll mul(ll a, ll b){return (a%mod * b%mod)%mod;}
ull poww(ull a,ull b){ull res=1;while(b){if(b&1){res*=a;}a=a*a;b>>=1;}return res;}
ll poww(ll a,ll b,ll MOD){ll res=1;while(b){if(b&1){res*=a;res%=MOD;}a=a*a;a%=MOD;b>>=1;}return res;}

#define dbg(x) cout<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define dbg4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;

//end of template

const int N = 2e5 + 5;

ll fac[N];
ll ifac[N];

ll ncr(ll n, ll r){
	return mul(fac[n], mul(ifac[r], ifac[n-r]));
}

void pre(){
	ifac[0] = fac[0] = 1;
	F(i, 1, N-1){
		fac[i] = mul(fac[i-1], i);
		ifac[i] = mul(ifac[i-1], poww(i, mod-2, mod));
	}
}

int main(int argc, char const *argv[])
{
	crap;
	ll n, m , k;
	cin >> n >> m >> k; 
	pre();
	ll ans = ncr(n*m -2 , k-2);
	ll d1 = 0, d2 = 0, d = 0;
	vll x, y;
	F(i, 1, n){
		F(j, 1, m){
			x.pb(i);
			y.pb(j);
		}
	}
	sort(all(x));
	sort(all(y));
	ll prev = 0;
	rep(i, sz(x)){
		d1 = add(d1, sub(mul(i, x[i]), prev));
		prev += x[i];
	}
	prev = 0;
	rep(i, sz(y)){
		d2 = add(d2, sub(mul(i, y[i]), prev));
		prev += y[i];
	}
	d = add(d1, d2);
	ans = mul(ans, d);
	cout << ans << endl;
	return 0;
}