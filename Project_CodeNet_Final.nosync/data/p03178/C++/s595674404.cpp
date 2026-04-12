#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define ull 		unsigned long long
#define ll 			long long
#define M 			1000000007
#define pb 			emplace_back
#define p_q 		priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define cset(a)		__builtin_popcountll(a)
#define hell 		(ull)1e9
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr<<endl; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int d,n,dp[10001][2][2][101];
vi l,r;
int solve(int pos,int f1,int f2,int rem)
{
	if(pos==n)
	{
		if(rem==0)
			return 1;
		return 0;
	}
	int &ans=dp[pos][f1][f2][rem];
	if(ans!=-1)
		return ans;
	ans=0;
	int ulmt=9,llmt=0;
	if(f1==0)
		ulmt=r[pos];
	if(f2==0)
		llmt=l[pos];
	rep(dgt,llmt,ulmt+1)
	{
		int nf1=f1,nf2=f2;
		if(dgt>llmt)
			nf2=1;
		if(dgt<ulmt)
			nf1=1;
		int nrem=(rem+dgt)%d;
		ans=(ans+solve(pos+1,nf1,nf2,nrem))%M;
	}
	return ans;
}
signed main(void)
{ios
	string k; 
	cin>>k>>d;
	for(char i:k)
		r.pb(i-'0');
	l.pb(1);
	rep(i,0,sz(r)-1)
	{
		l.pb(0);
	}
	reverse(all(l));
	n=sz(r);
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0,0,0)<<endl;
}