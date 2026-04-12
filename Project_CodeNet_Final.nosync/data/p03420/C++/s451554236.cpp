#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
ll max(ll a,ll b){
	return a>b?a:b;
}
void inp(){
	ll n,k,ans;scanf("%lld%lld", &n,&k);
	ans = 0;
	if( k ==  0)ans = n * n;
	else for(ll b = k + 1;b <= n; b++){
		ll c = n / b;
		ans += (b - 1 - k + 1) * c;
		ans += max((n % b - k + 1), 0);
		//printf("b:%lld %lld\n",b, ans);
	}
	printf("%lld\n", ans);
}
//b.cc by xsthunder at Sat Aug  4 13:53:44 2018
