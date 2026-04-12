#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;
 
inline void up(int &x,const int &y){if(x<y)x=y;}
inline void down(int &x,const int &y){if(x>y)x=y;}
const int maxn = 410000;
 
int n;
int li[maxn],ri[maxn];
struct node{int x,i,p;}a[maxn<<1]; int m;
inline bool cmp(const node x,const node y){return x.x==y.x?x.i<y.i:x.x<y.x;}
inline bool cmpp(const node x,const node y){return x.x==y.x?x.p<y.p:x.x<y.x;}
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y; scanf("%d%d",&x,&y); if(x>y) swap(x,y);
		li[i]=x,ri[i]=y;
		a[++m]=(node){x,i,0};
		a[++m]=(node){y,i,1};
	}sort(a+1,a+m+1,cmp);
	
	ll ans=LLONG_MAX;
	if(a[1].i!=a[m].i)
	{
		sort(a+1,a+m+1,cmpp);
		int l=2;for(;l<m&&a[l].p!=1;l++); l=a[l].x;
		down(l,li[a[m].i]);
		int mn=inf;
		for(int i=m-1;i>=2;i--)
		{
			down(mn,a[i].x-l); if(a[i].p==0) break;
			down(l,li[a[i].i]);
		}
		ans=(ll)(a[m].x-a[1].x)*(ll)mn;
	}
	int u1=0,d2=inf;
	for(int i=1;i<=n;i++)
	{
		up(u1,li[i]);
		down(d2,ri[i]);
	}
	ans=min(ans,(ll)(u1-a[1].x)*(ll)(a[m].x-d2));
	printf("%lld\n",ans);
	
	return 0;
}
