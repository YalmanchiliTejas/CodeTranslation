#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
ll l[maxn],r[maxn],m[maxn],a[maxn];
ll cal(ll x){ if(x<3) return 0;
	return max(max(l[x-1],r[x-1]),cal(x-2)+a[x]);
}
int main(){
	int n;scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i+=2){
		l[i]=l[i-2]+a[i-1];
		r[i]=max(r[i-2],l[i-2])+a[i];
	}if(n%2){
		printf("%lld\n",cal(n));
	}else printf("%lld\n",max(l[n],r[n]));
}