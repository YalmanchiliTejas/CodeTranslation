#include<bits/stdc++.h>
using namespace std;
int ans,n;
int head,tail;
int h[234234],a[234234];

int getbig(int l,int r,int x)
{
  while(1)
    {
	  int mid=(l+r)/2;
	  if(x<=h[mid]) 
	    {
	      if(l==mid) break;
		  l=mid;
		}
	  else r=mid;
	}
  return l+1;
}

int main()
{
	int i,t;
  scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  head=1,tail=1,ans=1;
  h[1]=a[1];
  for(i=2;i<=n;i++)
    {
	  if(a[i]<=h[tail]) ans++,h[++tail]=a[i];
	  else
	    {
	      h[head-1]=2e9;
		  t=getbig(head-1,tail+1,a[i]);
		  h[t]=a[i];
		}
	}
  printf("%d\n",ans);
} 