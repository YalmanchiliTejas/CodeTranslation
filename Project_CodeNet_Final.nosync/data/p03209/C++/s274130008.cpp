/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,k,pt[100],tot[100];

LL dfs(LL pos,LL lft)
{
	if(lft<=0) return 0LL;
	LL ret=0;
	lft--;
	if(lft>=tot[pos-1])
	{
		ret+=pt[pos-1];
		lft-=tot[pos-1];
	}
	else
	{
		ret+=dfs(pos-1,lft);
		return ret;
	}
	if(lft>0)
	{
		lft--;
		ret++;
	}
	if(lft==0) return ret;
	if(lft>=tot[pos-1])
	{
		ret+=pt[pos-1];
		lft-=tot[pos-1];
	}
	else
	{
		ret+=dfs(pos-1,lft);
		return ret;
	} 
	return ret;
}

int main()
{
	cin>>n>>k;
	pt[0]=1;
	tot[0]=1;
	repn(i,50)
	{
		tot[i]=tot[i-1]*2+3;
		pt[i]=pt[i-1]*2+1;
	}
	cout<<dfs(n,k)<<endl;
	rt0;
}