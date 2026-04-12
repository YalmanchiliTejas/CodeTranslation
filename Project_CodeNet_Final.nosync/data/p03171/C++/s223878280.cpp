#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)

lli dp[3010][3010];
lli vis[3010][3010];
lli n;
vector<lli> a;

lli f(lli l,lli r){
	if(l>r)return 0;
	if(vis[l][r])return dp[l][r];

	lli diff = n-(r-l+1);
	lli res;
	if(diff%2==0){
		res = -INF;
		res = max(res,f(l+1,r)+a[l]);
		res = max(res,f(l,r-1)+a[r]);
	}
	else{
		res = INF;
		res = min(res,f(l+1,r)-a[l]);
		res = min(res,f(l,r-1)-a[r]);
	}
	vis[l][r]=1;
	return dp[l][r]=res;
}

signed main(){

	cin>>n;
	a.resize(n);
	REP(i,0,n)cin>>a[i];

	REP(i,0,3010)REP(j,0,3010){
		dp[i][j]=0;
		vis[i][j]=0;
	}
	cout<<f(0,n-1)<<endl;

	return 0;
}