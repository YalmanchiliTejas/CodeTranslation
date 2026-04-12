#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int x,m,n,cnt,blag,t;
int ans,res;
bool flag;
int a[N],wzl[N];
signed main()
{
	cin>>n>>x>>m;
	memset(a,0,sizeof a);
	res=x;ans=res;wzl[1]=res;a[res]=1;
	for (register int i=2;i<=n;i++) 
	{
		res=res*res;
		if (res>=m) res%=m;
		if (a[res]!=0) {cnt=i-a[res];blag=a[res];wzl[i]=wzl[i-1]+res;t=i;flag=1;break;}
		else {a[res]=i;wzl[i]=wzl[i-1]+res;ans+=res;}
	}
	if (flag) 
	{
		ans+=(n-t)/cnt*(wzl[t]-wzl[blag]); 
		for (register int i=1;i<a[res];i++) x=x*x%m;
		for (register int i=a[res];i<a[res]+(n-t)%cnt;i++) ans+=x,x=x*x%m;
		if (t!=n) ans+=x;
	}  
	cout<<ans<<endl;
	return 0;
} 