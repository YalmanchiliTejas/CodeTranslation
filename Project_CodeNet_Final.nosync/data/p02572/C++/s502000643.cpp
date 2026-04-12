#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
using namespace std;
int ans=0,sum[200001];
int n,a[200001];
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n;
	sum[0]=0;
	REP(i,0,n){
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
	}
	REP(i,0,n){
		ans+=((sum[i+1]-a[i])%(long long)(1e9+7)*(a[i]%(long long)(1e9+7)))%(long long)(1e9+7);
		ans%=(long long)(1e9+7);
	}
	cout<<ans<<endl;
    return 0;
}
