#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define m_p			make_pair
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define sz(x)       (int)x.size()
#define f			first
#define debug		cout<<"##########3"<<endl
#define mod			1000000007
#define ll			long long int
#define lMax		LLONG_MAX
// queue<int> , prefix_sum(a,a+n) , reverse(a,a+n) , priority_queue <int> max heap , priority_queue <int, vector<int>, greater<int> > min heap;
// == precedence gretaer then &
ll n,m;
ll arr[3005];
// Prefix sum calculation wala dp !!!!
ll dp[3005][3005][2];
int main() {
    ll i,j,k,c=0,ans=0,t,z,x=0,y;
	cin>>n;
	rep(i,0,n){
		cin>>arr[i];
		dp[i][i][0] = arr[i];
		dp[i][i][1] = -arr[i];
	}
	for(int len=2;len<=n;len++){
		for(i=0;i<=n-len;i++){
			j = i+len-1;
			dp[i][j][0] = max(dp[i][j-1][1] + arr[j],dp[i+1][j][1] + arr[i]);
			dp[i][j][1] = min(dp[i][j-1][0] - arr[j],dp[i+1][j][0] - arr[i]);
		//	cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
		}
	}
	cout<<dp[0][n-1][0];
 	return 0;
}