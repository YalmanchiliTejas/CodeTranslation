#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 100005
#define rep(i, l, r) for(int i=l; i<=r; ++i)
using namespace std;
int t;
int x, m;
ll n;
int pos[N];
int f[N];
int main(){
	scanf("%lld%d%d", &n, &x, &m);
	ll ans=0;
	if(n<=m){
		rep(i, 1, n){
			f[i]=x;
			ans+=x;
			x=1ll*x*x%m;
		}
		printf("%lld", ans);
	}
	else{
		rep(i, 1, m+1){
			f[i]=x;
			if(pos[x]){
				rep(j, 1, pos[x]) ans+=f[j];
				rep(j, pos[x]+1, i) ans+=1ll*f[j]*((n-pos[x]+i-j)/(i-pos[x]));
				printf("%lld", ans);
				break;
			}
			pos[x]=i;
			x=1ll*x*x%m;
		}	
	}
	
	return 0;
}
	