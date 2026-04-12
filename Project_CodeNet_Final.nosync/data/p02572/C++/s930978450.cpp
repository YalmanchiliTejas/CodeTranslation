#include<bits/stdc++.h>
#define int			long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	ll pre[n];
	rep(i,0,n)cin>>a[i];;
	ll suff[n];
	suff[n-1]=a[n-1];
	for(ll i=n-2;i>=0;i--){
		suff[i]=(suff[i+1]+a[i])%hell;
	}	
	pre[0]=a[0];
	rep(i,1,n){
		pre[i]=(pre[i-1]*a[i])%hell;
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		ans=(ans+(a[i]*suff[i+1])%hell)%hell;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	return 0;
}