#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop") 
#define all(a) a.begin(),a.end()
#define bs binary_search
#define ll long long int
#define ps push_back
#define fs first
#define sc second
#define mkp make_pair
#define mod 1000000007
ll dp[3001][3001];
ll maxval(ll ar[],ll l,ll r,ll c){
	if(l==r){
		if(c%2==0) return ar[l];
		else return -ar[l];
	}

	if(dp[l][r]!=-1){
		return dp[l][r];
	}

	if(c%2==0){
		return dp[l][r]=max(ar[l]+maxval(ar,l+1,r,c+1),ar[r]+maxval(ar,l,r-1,c+1));
	}
	else {
		return dp[l][r]=min(maxval(ar,l+1,r,c+1)-ar[l],maxval(ar,l,r-1,c+1)-ar[r]);
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(dp,-1,sizeof(dp));

	ll i,j,k,l,n;
	cin>>n;

	ll ar[n];
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	k=maxval(ar,0,n-1,0);
	cout<<k;
	return 0;
}
//ctrl H replace