#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long
#define pq priority_queue
#define mp make_pair
#define pii pair<int,int>
#define mod 998244353

int lowbit(int x) {return x&(-x);}

int n;
ll a[3010];
ll dp[3010][3010][2];

ll getf(int l,int r,int c) {
	if (dp[l][r][c]!=-1) return dp[l][r][c];
	if (l==r) {
		if (c==0) return dp[l][r][c]=a[l];
		else return dp[l][r][c]=-a[l];
	}
	if (c==0) dp[l][r][c]=max(a[l]+getf(l+1,r,1),a[r]+getf(l,r-1,1));
	else dp[l][r][c]=min(getf(l+1,r,0)-a[l],getf(l,r-1,0)-a[r]);
	return dp[l][r][c];
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<getf(1,n,0);
	return 0;
}
