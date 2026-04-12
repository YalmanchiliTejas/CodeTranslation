#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[3005][3005][2],a[3005];
int n;
ll rec(int L,int R,int p){
	if(dp[L][R][p] >= -1e15) return dp[L][R][p];
	if(L > R) return 0LL;
	if(p == 0){
		ll x = -1e18;
		x = max(x,a[L]+rec(L+1,R,1-p));
		x = max(x,a[R]+rec(L,R-1,1-p));
		return dp[L][R][p] = x;
	}
	else{
		ll x = 1e18;
		x = min(x,-a[L]+rec(L+1,R,1-p));
		x = min(x,-a[R]+rec(L,R-1,1-p));return dp[L][R][p] = x;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	rep(i,3005)rep(j,3005)rep(k,2) dp[i][j][k]=-1e18;
	cout<<rec(1,n,0)<<endl;
}