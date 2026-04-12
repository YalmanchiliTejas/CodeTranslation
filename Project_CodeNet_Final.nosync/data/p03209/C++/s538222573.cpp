#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
int n;
unsigned long long f[60],g[60],x,ans;
void dfs(int a){
	if (a==0){
		if (x==1) ans++;
		return;
	}
	if (x){
		x--;
		if (x>=f[a-1]){
			x-=f[a-1];
			ans+=g[a-1];
			if (x){
				x--;
				ans++;
				if (x>=f[a-1]) ans+=g[a-1];else dfs(a-1);
			}
		}else dfs(a-1);
	}
}
int main(){
	scanf("%d%llu",&n,&x);
	f[0]=g[0]=1;
	fo(i,1,n){
		f[i]=f[i-1]*2+3;
		g[i]=g[i-1]*2+1;
	}
	dfs(n);
	printf("%llu\n",ans);
	return 0;
}