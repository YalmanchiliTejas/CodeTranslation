#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=998244353;

LL n,t,n2=1,a[3010],dp[3010][3010],dat[3010][30010],ans;

void upd(LL kk,LL k,LL val)
{
	dat[kk][k]=val;
	while(k>0)
	{
		k=(k-1)/2;
		dat[kk][k]=(dat[kk][k*2+1]+dat[kk][k*2+2])%MOD;
	}
}

LL query(LL kk,LL k,LL lb,LL ub,LL tlb,LL tub)
{
	if(ub<tlb||tub<lb) return 0;
	if(tlb<=lb&&ub<=tub) return dat[kk][k];
	return query(kk,k*2+1,lb,(lb+ub)/2,tlb,tub)+query(kk,k*2+2,(lb+ub)/2+1,ub,tlb,tub);
}

int main()
{
	cin>>n>>t;
	while(n2<3000) n2*=2;
	rep(i,n)
	{
		cin>>a[i];
		dp[i][a[i]]=i+1;
		upd(a[i],i+n2-1,i+1);
	}
	repn(i,n-1)
	{
		rep(j,3001)
		{
			if(j-a[i]<0) continue;
			dp[i][j]=(dp[i][j]+query(j-a[i],0,0,n2-1,0,i-1))%MOD;
			//if(j<=10) cout<<i<<' '<<j<<' '<<query(j-a[i],0,0,n2-1,0,i-1)<<endl;
			upd(j,i+n2-1,dp[i][j]);
			//if(j==5&&i==3) cout<<dp[i][j]<<'p'<<' '<<query(5,0,0,n2-1,0,3)<<endl;
		}
	}
	rep(i,n) ans=(ans+dp[i][t]*(n-i)%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}