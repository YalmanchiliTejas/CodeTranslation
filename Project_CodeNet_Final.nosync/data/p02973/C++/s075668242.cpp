#include<bits/stdc++.h>
using namespace std;
int n=0,a[100001],f[100001],s[100001],mo=100000,cnt,ans;
int lowbit(int k)
{
	return k&-k;
}
int main() 
{
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	s[i]=a[i];
    }	
    sort(s+1,s+n+1);
	cnt=unique(s+1,s+n+1)-s-1;
	for(int i=1;i<=n;i++)
	a[i]=lower_bound(s+1,s+cnt+1,a[i])-s;
    for(int i=1;i<=n;i++)
    {
    	int mx=0;
		for(int j=a[i];j<=mo;j+=lowbit(j))
			mx=max(mx,f[j]);
		mx++;
		for(int j=a[i];j>=1;j-=lowbit(j))
			f[j]=max(f[j],mx);
		ans=max(ans,mx);
	}
    cout<<ans<<endl;
}