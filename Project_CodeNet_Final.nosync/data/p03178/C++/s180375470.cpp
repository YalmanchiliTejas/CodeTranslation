
#include<bits/stdc++.h>
using namespace std;

#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define inp(x) cin>>x
#define print(x) cout<<x
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define reset(d,val) memset(d,val,sizeof(d))
#define sort(v) sort(v.begin(),v.end())
#define sort_arr(arr,i,f) sort(arr+i,arr+f)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

int n;
string s;
ll dp[10005][2][100];

ll f(int i,int t,int md,int d) {
	if(i==n) return (md==0);
	if(dp[i][t][md]!=-1) return dp[i][t][md];
	ll ans = 0;
	int ub = t?(s[i]-'0'):9;
	for(int j=0;j<=ub;j++) {
		ans = (ans+f(i+1,t&(ub==j),(md+j)%d,d))%mod;
	}
	return dp[i][t][md] = (ans+mod)%mod;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	n = s.length();
	//cout<<n<<endl;
	int d;
	cin>>d;
	memset(dp,-1,sizeof(dp));
	ll ans = f(0,1,0,d);
	ans = (ans-1);
	if(ans<0) ans+=mod;
	ans%=mod;
	cout<<ans;
	return 0;
}
