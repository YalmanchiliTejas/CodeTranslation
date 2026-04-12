#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<map>
#include<set>
#include<string>
#include<vector>

#define gec getchar
#define FILE(F) freopen(F".in","r",stdin),freopen(F".out","w",stdout)
#define DEBUG fprintf(stderr,"Passing [%s] in Line (%d)\n",__FUNCTION__,__LINE__);
typedef long long ll;
template<class T>
inline void read(T&x)
{
	x=0;bool f=0;char c=gec();
	for(;c<'0'||c>'9';c=gec())f=(c=='-');
	for(;c>='0'&&c<='9';c=gec())x=x*10+c-'0';
	x=f?-x:x;
}

const int MAXN(100010);
struct Node{int v,a,b;}L[MAXN<<1];
bool cmp3(Node S,Node T){return S.v<T.v;}
int x[MAXN],y[MAXN],n,now,Ans;
struct Data
{
	int x,y,num;
}A[MAXN];
int f[MAXN];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void Union(int a,int b)
{
	int fa=gf(a),fb=gf(b);
	if(fa!=fb)f[fa]=fb;
}
bool cmp1(Data S,Data T){return S.x<T.x;}
bool cmp2(Data S,Data T){return S.y<T.y;}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(A[i].x),read(A[i].y),A[i].num=i;
	std::sort(A+1,A+1+n,cmp1);
	for(int i=2;i<=n;i++)L[++now]=(Node){A[i].x-A[i-1].x,A[i].num,A[i-1].num};
	std::sort(A+1,A+1+n,cmp2);
	for(int i=2;i<=n;i++)L[++now]=(Node){A[i].y-A[i-1].y,A[i].num,A[i-1].num};	
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)Union(x[i],y[i]);
	std::sort(L+1,L+1+now,cmp3);
	for(int i=1;i<=now;i++)
	{
		int a=L[i].a,b=L[i].b,v=L[i].v;
		int fa=gf(a),fb=gf(b);
		if(fa!=fb)
		{
			f[fa]=fb;Ans+=v;
		}
	}
	printf("%d\n",Ans);
	return 0;
}