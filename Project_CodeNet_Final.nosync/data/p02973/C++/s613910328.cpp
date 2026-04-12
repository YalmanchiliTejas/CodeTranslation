#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;
int n,m,a[200009],dp[200009],f[200009],b[200009];
void update(int x,int val)
{
  for (;x<=m;x+=x&-x) f[x]=max(f[x],val);
}
int query(int x)
{
  int ans=0;
  for (;x;x-=x&(-x))ans=max(ans,f[x]);
  return ans;
}
int main()
{
  scanf("%d",&n);
  for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
  sort(b+1,b+1+n);
  m=unique(b+1,b+1+n)-b-1;
  for (int i=1;i<=n;i++) 
  {
   a[i]=lower_bound(b+1,b+1+m,a[i])-b;
  }
  for (int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
  int now=0,ans=0;
  for (int i=1;i<=n;i++) 
  {
  	now=query(a[i])+1;
  	update(a[i],now);
  	ans=max(ans,now);
  }
  printf("%d\n",ans);
  return 0;
} 