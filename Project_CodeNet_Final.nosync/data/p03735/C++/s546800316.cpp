#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n;
pi x[200010];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d%d",&x[i].aa,&x[i].bb);
	   if(x[i].aa>x[i].bb)
	     swap(x[i].aa,x[i].bb);
	  }
	sort(x+1,x+n+1);
	for(i=1,j=2e9,k=0;i<=n;i++)
	  j=min(j,x[i].bb),k=max(k,x[i].bb);
	p=(L)(x[n].aa-x[1].aa)*(k-j);
	l=k-x[1].aa;
	x[n+1].aa=2e9;
	for(i=1,j=2e9,k=x[n].aa;i<=n;i++)
	  {
	   j=min(j,x[i].bb);
	   k=max(k,x[i].bb);
	   p=min(p,(L)l*(k-min(j,x[i+1].aa)));
	  }
	printf("%lld\n",p);
	return 0;
}
