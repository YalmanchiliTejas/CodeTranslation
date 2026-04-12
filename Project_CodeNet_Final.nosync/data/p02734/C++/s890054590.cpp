#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
#define F(i,x,y) for (int i=x; i<=y; i++)
#define D(i,x,y) for (int i=x; i>=y; i--)
using namespace std;
const int N=3333;
ll f[N];
int a[N];
int n,k;
ll p=998244353;
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n) scanf("%d",&a[i]);
	ll ans=0;
	F(i,1,n){
		f[0]=i;
		D(j,k,a[i]) f[j]=(f[j]+f[j-a[i]])%p;
		ans=(ans+f[k])%p;
	}
	printf("%lld\n",ans);
	return 0;
}