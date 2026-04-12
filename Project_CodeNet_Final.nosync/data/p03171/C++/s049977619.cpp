/*
 *  author: chw0501
 *  created: 15.04.2020 11:24:07(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;

//dp[i][j]: a[i]~a[j]까지 수가 남았을때 현재 플레이어가 얻을 수 있는 최대 점수
ll dp[3001][3001];
ll a[3001];
ll sum[3001];

ll solve(int i,int j){
	ll& ret=dp[i][j];
	if(ret!=-1ll) return ret;
	if(i==j) return ret=a[i];
	ret=0;
	ll s=sum[j]-sum[i-1];
	ret=max(ret,s-solve(i+1,j));
	ret=max(ret,s-solve(i,j-1));
	return ret;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	memset(dp,-1ll,sizeof(dp));
	ll x=solve(1,n);
	ll y=sum[n]-x;
	cout<<x-y;
	return 0;
}