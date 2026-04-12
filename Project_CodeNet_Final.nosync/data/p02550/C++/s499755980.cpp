#include <cstdio>
#include <cstring>
#define max_m 100000
#define max_min_n_m max_m
using namespace std;
long long sum[max_min_n_m+1];
int vis[max_m+1];
int main(){
	long long n,x;
	int m;
	scanf("%lld%lld%d",&n,&x,&m);
	sum[1]=x,memset(vis,0,sizeof(vis));
	for(int i=1; ++i<=n; sum[i]=sum[i-1]+x,vis[x]=i){
		x=x*x%m;
		if(!x){
			printf("%lld\n",sum[i-1]);
			return 0;
		}
		if(vis[x]){
			printf("%lld\n",(sum[i-1]-sum[vis[x]-1])*((n-vis[x]+1)/(i-vis[x]))+sum[vis[x]+(n-vis[x]+1)%(i-vis[x])-1]);
			return 0;
		}
	}
	printf("%lld\n",sum[n]);
	return 0;
}