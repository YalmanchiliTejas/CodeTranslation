#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=400005;
int size[N],ne[N],tot,fi[N],zz[N],x,y,n,cnt,d[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x,int y){
	size[x]=1;int cnt=0;
	for (int i=fi[x];i;i=ne[i])if (zz[i]!=y){
		dfs(zz[i],x);
		size[x]+=size[zz[i]];
		cnt+=size[zz[i]]&1;
	}
	if (cnt>=2){
		puts("First");
		exit(0);
	}
}
signed main(){
	scanf("%lld",&n);
	if (n&1){
		puts("First");
		return 0;
	}
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		jb(x,y);jb(y,x);
		d[x]++;d[y]++;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (d[i]>1){
			dfs(i,0);
			break;
		}
	puts("Second");
}