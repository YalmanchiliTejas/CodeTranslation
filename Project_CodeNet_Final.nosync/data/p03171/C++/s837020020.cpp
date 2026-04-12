#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,a[10005],f[3005][3005];
int F(int i,int j)
{
	if(f[i][j]!=-1) return f[i][j];
	else if(i>j)
	{
		return 0;
	}
	else
	{
		int res;
		if((i-1+n-j)%2==0)
		{
			res=max(F(i+1,j)+a[i],F(i,j-1)+a[j]);
		}
		else 
		{
			res=min(F(i+1,j)-a[i],F(i,j-1)-a[j]);
		}
		f[i][j]=res;
		return res;
	}
	
}
main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,-1,sizeof(f));
	cout<<F(1,n);
}