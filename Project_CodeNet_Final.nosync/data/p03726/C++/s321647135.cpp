#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
struct edge{int x, y, next;}a[N*2];
int n, l, p[N], x, y, du[N], flag[N], sum, s[N], op, cl, d[N], b[N], c[N];
inline void add(int x, int y){a[++l].x=x; a[l].y=y; a[l].next=p[x]; p[x]=l;}
int main(){
	scanf("%d", &n);
	l=0; memset(p, 0, sizeof(p)); memset(du, 0, sizeof(du));
	for(int i=1; i<=n-1; i++){scanf("%d%d", &x, &y); add(x, y); add(y, x); du[x]++; du[y]++;}
	memset(flag, 0, sizeof(flag)); sum=n;
	memset(s, 0, sizeof(s));
	op=cl=0; for(int i=1; i<=n; i++){if(du[i]==1)d[++cl]=i; if(!du[i]){printf("First"); return 0;}}
	while(sum){
		l=0; while(op<cl){op++; b[++l]=d[op]; for(int j=p[d[op]]; j; j=a[j].next)if(!flag[a[j].y])c[l]=a[j].y;}
		for(int i=1; i<=l; i++)if(c[i]){s[c[i]]++; if(s[c[i]]>=2){printf("First"); return 0;}}
		for(int i=1; i<=l; i++){flag[b[i]]=1; sum--;}
		for(int i=1; i<=l; i++)if(!flag[c[i]]){flag[c[i]]=1; sum--;}
		for(int i=1; i<=l; i++)
			for(int j=p[c[i]]; j; j=a[j].next)if(!flag[a[j].y]){
				du[a[j].y]--; if(!du[a[j].y]){printf("First"); return 0;}
				if(du[a[j].y]==1)d[++cl]=a[j].y;
			}
	}
	printf("Second");
	return 0;
}