#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9+7
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define vll vector<ll>
#define rep(i,j,n) for(int i=j;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define inf 1e17
priority_queue<pll,vector<pll>,greater<pll> >pq;
priority_queue<ll,vector<ll>,greater<ll> >pq1;

ll n;
ll arr[3001];
ll dp[3001][3001][2];

ll solve(ll i, ll j, ll p){
	if(i>j)
		return 0;
	if(i==j){
		if(p==0)
			return arr[i];
		else
			return -1*arr[i];
	}
	if(dp[i][j][p] != -1)
		return dp[i][j][p];
	if(p==0){
		dp[i][j][p]=-1*inf;
		dp[i][j][p]=max(dp[i][j][p],arr[i]+solve(i+1,j,1));
		dp[i][j][p]=max(dp[i][j][p],arr[j]+solve(i,j-1,1));
	}
	else{
		dp[i][j][p]=inf;
		dp[i][j][p]=min(dp[i][j][p],solve(i+1,j,0)-arr[i]);
		dp[i][j][p]=min(dp[i][j][p],solve(i,j-1,0)-arr[j]);
	}
	return dp[i][j][p];
}

int main(){
	if(fopen("input.txt", "r"))
	freopen("input.txt", "r", stdin),
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    for(int i=0;i<=3000;i++){
    	for(int j=0;j<3001;j++){
    		dp[i][j][0]=-1;
    		dp[i][j][1]=-1;
    	}
    }

    ll ans=solve(0,n-1,0);
    cout<<ans<<"\n";
    
    return 0;
}
