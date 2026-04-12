#include<bits/stdc++.h>
using namespace std;
long long a[100010],x,m,n,cnt,blag,cx=0,t;
long long ans=0,res,jyz[100010]={0};
int main()
{
	cin>>n>>x>>m;
	memset(a,0,sizeof a);
	res=x;ans=res;jyz[1]=res;a[res]=1;
	for (register int i=2;i<=n;i++) 
	{
		res=res*res;
		if (res>=m) res%=m;
		//if (res==0) break;
		if (a[res]!=0) {cnt=i-a[res];blag=a[res];jyz[i]=jyz[i-1]+res;t=i;cx=233;break;}
		else {a[res]=i;jyz[i]=jyz[i-1]+res;ans+=res;}
	}
	if (cx==233) 
	{
		ans+=(n-t)/cnt*(jyz[t]-jyz[blag]); 
		for (register int i=1;i<a[res];i++) x=x*x%m;
		for (register int i=a[res];i<a[res]+(n-t)%cnt;i++) ans+=x,x=x*x%m;
		if (t!=n) ans+=x;
	}  
	cout<<ans<<endl;
	return 0;
} 