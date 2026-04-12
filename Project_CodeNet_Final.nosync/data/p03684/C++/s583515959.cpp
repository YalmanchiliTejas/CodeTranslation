#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

int n,l[maxn<<1],r[maxn<<1],w[maxn<<1],cnt,rk[maxn<<1];

struct Node{
	int x,y,id;
}a[maxn];

bool cmp1(Node a,Node b)
{
	return a.x<b.x;
}


bool cmp2(Node a,Node b)
{
	return a.y<b.y;
}

int Dst(Node a,Node b)
{return min(abs(a.x-b.x),abs(a.y-b.y));}

bool cmp3(int a,int b)
{
	return w[a]<w[b];
}

int fa[maxn<<1];

int gf(int k)
{
	if (fa[k]==k) return k;
	else return fa[k]=gf(fa[k]);
}

int main()
{
	
	#ifdef WXL
	freopen("in.txt","r",stdin);
	#endif
	
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+n+1,cmp1);
	for (int i=1;i<n;++i) l[++cnt]=a[i].id,r[cnt]=a[i+1].id,w[cnt]=Dst(a[i],a[i+1]);
	sort(a+1,a+n+1,cmp2);
	for (int i=1;i<n;++i) l[++cnt]=a[i].id,r[cnt]=a[i+1].id,w[cnt]=Dst(a[i],a[i+1]);
	
	for (int i=1;i<=cnt;++i) rk[i]=i;
	sort(rk+1,rk+cnt+1,cmp3);
	
	long long ans=0;
	
	for (int i=1;i<=n;++i )fa[i]=i;

	for (int i=1;i<=cnt;++i){
		int L=l[rk[i]],R=r[rk[i]];
		if (gf(L)!=gf(R)){
			ans+=w[rk[i]];
			fa[gf(L)]=gf(R);
		}
	}
	cout<<ans<<endl;
}