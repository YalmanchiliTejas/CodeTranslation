#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli n;
vector<lli> a;

lli dp[3010][3010];
bool vis[3010][3010];

lli func(lli left,lli right){
	if(left>right)return 0;
	if(vis[left][right])return dp[left][right];

	vis[left][right] = true;
	lli diff = left + (n-1)-right;

	lli res = INF;
	if(diff % 2==0){
		res *= -1;
		res = max(res,func(left+1,right)+a[left]);
		res = max(res,func(left,right-1)+a[right]);
	}
	else{
		res = min(res,func(left+1,right)-a[left]);
		res = min(res,func(left,right-1)-a[right]);
	}
	vis[left][right]=true;
	return dp[left][right] = res;
}

signed main(){

	cin>>n;
	a.resize(n);
	REP(i,0,n)cin>>a[i];

	cout<<func(0,n-1)<<endl;
	return 0;
}