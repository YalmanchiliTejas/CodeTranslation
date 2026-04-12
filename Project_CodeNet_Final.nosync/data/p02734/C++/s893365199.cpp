#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3005;
ll n,m,a[N],dp[N],mod=998244353,ans;
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		cin>>a[i];
		if(a[i]<m)
			ans=(ans+dp[m-a[i]]*(n-i+1))%mod;
		if(a[i]==m)
			ans=(ans+i*(n-i+1))%mod;
		f_(j,N-2,a[i]+1)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		dp[a[i]]=(dp[a[i]]+i)%mod;
	}
	cout<<ans;
}