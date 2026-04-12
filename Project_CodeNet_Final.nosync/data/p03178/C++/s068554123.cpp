#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<pair<int,int>,null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>   ordered_set;
const int N=1e4+10, mod=1e9+7;
ll dp[N][100][2]; string s; int d;

ll calc(int i,int sum,int less){
	if( i==(int)s.length() ){
		return (sum==0);
	}
	ll &ans= dp[i][sum][less];
	if(ans!=-1) return ans;
	int mx=(less?9:(s[i]-'0'));
	ans=0;
	for(int j=0;j<=mx;j++){
		ans+=calc(i+1, (sum+j)%d, less|(j!=mx) );
		if(ans>=mod) ans-=mod;
	}
	ans%=mod;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin>>s>>d;
	memset(dp,-1,sizeof dp);
	cout<<(calc(0,0,0)-1+mod)%mod;
}

// check for any potential overflow before submitting
