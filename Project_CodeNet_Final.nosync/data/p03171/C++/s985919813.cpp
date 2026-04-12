/* ****GT_18**** */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  3005

ll n;
ll a[N];
ll dp[N][N][2];


ll solve(ll st, ll en, bool player){
	if(dp[st][en][player]!=-1)return dp[st][en][player];
	if(st==en){
		if(player)return dp[st][en][player]=-a[st];
		else return dp[st][en][player]=a[st];
	}
	ll a1 = solve(st+1,en,1-player);
	ll a2 = solve(st, en-1, 1-player);
	if(player){
		return dp[st][en][player]=min(a1-a[st],a2-a[en]);
	}
	else{
		return dp[st][en][player]=max(a1+a[st],a2+a[en]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	rep(i,0,N)rep(j,0,N)dp[i][j][0]=dp[i][j][1]=-1;
	while(TESTS--)
	{
			cin>>n;
			rep(i,0,n)cin>>a[i];
			cout<<solve(0,n-1,0)<<endl;
	}	
	return 0;
}