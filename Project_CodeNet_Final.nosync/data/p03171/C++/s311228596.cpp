#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int MAXN=3010;
int n;
int a[MAXN];
ll dp[2][MAXN][MAXN];
ll solve(int pl,int lo,int hi){
	if(lo>hi) return 0;
	ll &ret=dp[pl][lo][hi];
	if(ret) return ret;
	if(!pl) ret=max(solve(1,lo+1,hi)+a[lo],solve(1,lo,hi-1)+a[hi]);
	if(pl) ret=min(solve(0,lo+1,hi)-a[lo],solve(0,lo,hi-1)-a[hi]);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<solve(0,0,n-1)<<"\n";
	return 0;
}