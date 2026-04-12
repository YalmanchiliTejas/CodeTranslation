#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,x,m,l,r;
int a[1000005],pre[1000005];

map<int,int> ma;

signed main()
{
	cin>>n>>x>>m;
	a[1]=x;
	pre[1]=x;
	ma[x]=1;
	for (int i=2;i<=10*m;i++)
	{
		a[i]=(a[i-1]*a[i-1])%m;
		if (ma[a[i]])
		{
			l=ma[a[i]];
			r=i-1;
			break;
		}
		ma[a[i]]=i;
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0,tim,lef,tot=0,tot2=0;
	ans=pre[l-1];
	tim=(n-(l-1))/(r-l+1);
	lef=n-(l-1)-tim*(r-l+1);
	
	for (int i=l;i<=l+lef-1;i++)  tot+=a[i];
	for (int i=l;i<=r;i++)  tot2+=a[i];
	cout<<ans+tot2*tim+tot<<endl;
	
	return 0;
}