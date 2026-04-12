/*input
10 10
3 1 4 1 5 9 2 6 5 3
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define rep(i,j,n) for(i=j;i<n;i++)
#define repi(i,j,n) for(i=j;i>n;i--)
#define inf 100001
#define M 998244353
#define ll long long
#define ld long double
#define vll vector<long long>
#define vi vector<int>
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<long long,long long> >
#define pb push_back
#define pf pop_front
#define F first
#define S second
#define endl '\n'

using namespace std;
using namespace __gnu_pbds; 

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll power(ll a,ll m,ll mod){
	ll ans=1;
	while(m){
		if(m%2){
			ans*=a;
			ans%=(mod);
		}
		a=(a*a)%(mod);
		m>>=1;
	}
	return ans;
}


void init(ll* a,ll n,ll val){
	for(ll i=0;i<n;i++)
		a[i]=val;
}

ll dp[3001][3001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	ll t=1,i,j;
	ll n,s;
	cin>>n>>s;
	ll a[n];
	rep(i,0,n)cin>>a[i];
	ll ans=0;
	rep(i,0,n+1)rep(j,0,s+1)dp[i][j]=0;
	dp[0][a[0]]=1;
	ans+=((dp[0][s]*n)%M)%M;
	rep(i,1,n){
		ll k=a[i];
		rep(j,0,s+1)dp[i][j]=dp[i-1][j];
		dp[i][k]+=(i+1);
		dp[i][k]%=M;
		for(j=1;j+k<s+1;j++){
			dp[i][j+k]+=dp[i-1][j];
			dp[i][j+k]%=M;
		}
		ans+=((((dp[i][s]-dp[i-1][s]+M)%M)*(n-i))%M);
		ans%=M;
		//rep(j,0,s+1)cout<<dp[i][j]<<" ";
		//cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}


