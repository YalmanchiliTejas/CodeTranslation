#include<cstdio>
#include<algorithm>
#define MN 210001
using namespace std;

const int MOD=1e9+7;
int n,m,fa[MN],num=0;
long long mmh=0;
struct na{int x,y,p;}p[MN];
struct bi{int x,y,z;}B[MN];
bool cmpx(na a,na b){return a.x<b.x;}
bool cmpy(na a,na b){return a.y<b.y;}
bool cmp(bi a,bi b){return a.z<b.z;}
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].p=i,fa[i]=i;
	sort(p+1,p+1+n,cmpx);
	for (int i=2;i<=n;i++) B[++num].x=p[i-1].p,B[num].y=p[i].p,B[num].z=p[i].x-p[i-1].x;
	sort(p+1,p+1+n,cmpy);
	for (int i=2;i<=n;i++) B[++num].x=p[i-1].p,B[num].y=p[i].p,B[num].z=p[i].y-p[i-1].y;
	sort(B+1,B+1+num,cmp);
	for (int i=1;i<=num;i++){
		B[i].x=gf(B[i].x);B[i].y=gf(B[i].y);
		if (B[i].x!=B[i].y) fa[B[i].x]=B[i].y,mmh+=B[i].z;
	}
	printf("%lld\n",mmh);
}