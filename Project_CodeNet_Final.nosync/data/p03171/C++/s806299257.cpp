#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

int n,a[3010];
ll dp[3010][3010][2];

ll dfs(int l,int r,int t){
	if(dp[l][r][t]!=-1)return dp[l][r][t];
	if(l==r){
		if(!t)return a[l];
		else return -a[l];
	}
	ll res=0;
	if(t==0)res=max(dfs(l+1,r,1)+a[l],dfs(l,r-1,1)+a[r]);
	else res=min(dfs(l+1,r,0)-a[l],dfs(l,r-1,0)-a[r]);
	return dp[l][r][t]=res;
}

void input(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	return;
}

void solve(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=dp[i][j][1]=-1;
		}
	}
	cout<<dfs(0,n-1,0)<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}