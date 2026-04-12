#include<cstdio>
#include<cstring>
#include<algorithm>
struct node{
	int x,y,xh;
	bool operator <(const node&a)const{
		return x<a.x;
	}
}a[100010],b[100010];
struct edge{
	int d,d1,dat;
	bool operator <(const edge&a)const{
		return dat<a.dat;
	}
}e[300010];
int n,cnt,f[100010];
long long ans;
inline bool cmp(const node&a,const node&b){return a.y<b.y;}
template<class T>
inline void read(T&a){
	char c=getchar();
	for(a=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
}
inline int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	read(n);for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)read(a[i].x),read(a[i].y),a[i].xh=i,b[i]=a[i];
	std::sort(a+1,a+1+n);std::sort(b+1,b+1+n,cmp);
	for(int i=1;i<n;i++)e[++cnt]=(edge){a[i].xh,a[i+1].xh,a[i+1].x-a[i].x};
	for(int i=1;i<n;i++)e[++cnt]=(edge){b[i].xh,b[i+1].xh,b[i+1].y-b[i].y};
	std::sort(e+1,e+1+cnt);
	for(int i=1;i<=cnt;i++)
		if(gf(e[i].d)!=gf(e[i].d1)){
			int fx=gf(e[i].d),fy=gf(e[i].d1);
			f[fx]=fy;ans+=e[i].dat;
		}
	printf("%lld\n",ans);return 0;
}