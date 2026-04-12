#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=3003;
ll dp[N][N][2];

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	fr(i,0,n)
	cin>>arr[i];
	fr(i,0,n){
		if(n&1)
			dp[i][i][0]=arr[i];
		else
			dp[i][i][1]=-arr[i];
	}
	fr(l,2,n+1){
		fr(i,0,n-l+1){
			int j=i+l-1;
			if((l&1)==(n&1)){
				dp[i][j][0]=max(arr[i]+dp[i+1][j][1],arr[j]+dp[i][j-1][1]);
			}
			else{
				dp[i][j][1]=min(dp[i+1][j][0]-arr[i],dp[i][j-1][0]-arr[j]);
			}
		}
	}
	cout<<dp[0][n-1][0]<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}