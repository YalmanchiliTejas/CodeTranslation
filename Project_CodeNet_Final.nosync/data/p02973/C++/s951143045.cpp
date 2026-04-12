#include<bits/stdc++.h>
#define FOR(i,x,y) for(int i=(x),i##END=(y);i<=i##END;++i)
#define DOR(i,x,y) for(int i=(x),i##END=(y);i>=i##END;--i)
template<typename T,typename _T>inline bool chk_min(T &x,const _T y){return y<x?x=y,1:0;}
template<typename T,typename _T>inline bool chk_max(T &x,const _T y){return x<y?x=y,1:0;}
typedef long long ll;
const int N=2e5+5;
int c[N];
int a[N];
int disc[N],D;
int n;

void update(int k,int val)
{
	for(;k>0;k-=k&-k)chk_max(c[k],val);
}

int query(int k)
{
	int res=0;
	for(;k<=D;k+=k&-k)chk_max(res,c[k]);
	return res;
}

int main()
{
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&a[i]);
	FOR(i,1,n)disc[++D]=a[i];
	std::sort(disc+1,disc+1+D);
	FOR(i,1,n)a[i]=std::lower_bound(disc+1,disc+1+D,a[i])-disc;
	int ans=0;
	FOR(i,1,n)
	{
		int res=query(a[i])+1;
		update(a[i],res);
		chk_max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
