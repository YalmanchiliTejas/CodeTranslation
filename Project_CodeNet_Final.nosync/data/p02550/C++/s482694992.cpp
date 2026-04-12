#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxm=1e5;
ll n;
int x,m,s,id;
ll a[maxm+5],pres[maxm+5],ss[maxm+5],tots;
int used[maxm+5];
int main(){
	scanf("%lld",&n);
	scanf("%d %d",&x,&m);
	a[1]=x;
	for(s=1;!used[a[s]];s++){
		used[a[s]]=s;
		a[s+1]=a[s]*a[s]%m;
		pres[s]=pres[s-1]+a[s];
	}
	tots+=pres[used[a[s]]-1];
	for(int i=used[a[s]];i<s;i++)
		ss[i-used[a[s]]+1]=ss[i-used[a[s]]]+a[i];
	n=n-used[a[s]]+1; s-=used[a[s]];
	//printf("%lld %d\n",n,s);
	if(a[s]==0) printf("%lld\n",pres[s-1]);
	else printf("%lld\n",ss[s]*(n/s)+tots+ss[n%s]);
	return 0;
}
