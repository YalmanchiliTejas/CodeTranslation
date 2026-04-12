#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
ll n,x,m;
int vis[N],id=1;
ll pre[N];
int main(){
	scanf("%lld%lld%lld",&n,&x,&m);
	ll ans=0;
	while(n--){
		vis[x]=id++;
		pre[x]=ans;
		ans+=x;
		x=x*x%m;
		if(vis[x]>0){
			int jie=(id-vis[x]);
			ans+=(ans-pre[x])*(n/jie);
			n%=jie; 
		}
	} 
	printf("%lld\n",ans);
	return 0;
}