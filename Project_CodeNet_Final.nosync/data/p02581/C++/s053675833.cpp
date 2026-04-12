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

const LL MOD=1e9+7;

int n,a[6010],nxt[6010],dp[6010][6010],add=0,ans=0;
vector <int> v;

int point(int i,int j,int k)
{
	return (v[i]==v[j]&&v[j]==v[k] ? 1:0);
}

void trans(int i,int j,int k)
{
	if(k>=v.size()) return;
	if(k==v.size()-1)
	{
		ans=max(ans,dp[i][j]+point(i,j,k));
		return;
	}
	//rep(a,3) for(int b=a+1;b<3;b++) dp[k+a][k+b]=max(dp[k+a][k+b],dp[i][j]+point(i,j,k+3-a-b));
	dp[k][k+1]=max(dp[k][k+1],dp[i][j]+point(i,j,k+2));
	dp[k][k+2]=max(dp[k][k+2],dp[i][j]+point(i,j,k+1));
	dp[k+1][k+2]=max(dp[k+1][k+2],dp[i][j]+point(i,j,k)); 
	
	dp[i][k]=max(dp[i][k],dp[i][j]+point(j,k+1,k+2));
	dp[i][k+1]=max(dp[i][k+1],dp[i][j]+point(j,k,k+2));
	dp[i][k+2]=max(dp[i][k+2],dp[i][j]+point(j,k,k+1));
	
	dp[j][k]=max(dp[j][k],dp[i][j]+point(i,k+1,k+2));
	dp[j][k+1]=max(dp[j][k+1],dp[i][j]+point(i,k,k+2));
	dp[j][k+2]=max(dp[j][k+2],dp[i][j]+point(i,k,k+1));
}

int main()
{
	cin>>n;
	repn(i,n*3) scanf("%d",&a[i]);
	v.pb(0);
	repn(i,n*3)
	{
		if(i+2<=n*3&&i%3==0&&a[i]==a[i+1]&&a[i+1]==a[i+2])
		{
			add++;
			i=i+2;
			continue;
		}
		v.pb(a[i]);
	}
	rep(i,6005) nxt[i]=-1;
	repn(i,v.size()-1)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v[i]==v[j])
			{
				nxt[i]=j;
				break;
			}
		}
	}
	rep(i,6005) rep(j,6005) dp[i][j]=-1;
	dp[1][2]=0;
	repn(i,v.size()-1) for(int j=i+1;j<v.size();j++)
	{
		if(dp[i][j]==-1) continue;//cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<nxt[i]<<' '<<nxt[j]<<endl;
		ans=max(ans,dp[i][j]);
		trans(i,j,(j+3)/3*3);
		if(nxt[i]!=-1&&j/3*3<nxt[i]/3*3) trans(i,j,nxt[i]/3*3);
		if(nxt[j]!=-1&&j/3*3<nxt[j]/3*3) trans(i,j,nxt[j]/3*3);
	}
	cout<<ans+add<<endl;//cout<<ans<<endl;
	//rep(i,v.size()) cout<<v[i]<<' ';
	return 0;
}
/*
5
1 5 2 1 3 3 1 1 5 4 4 4 4 4 3 
*/