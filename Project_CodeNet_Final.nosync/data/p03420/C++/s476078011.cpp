#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL n,k,ans;
LL min(LL x,LL y) {
    if (x<y) return x;
    return y;
}
int main() {
    scanf("%lld%lld",&n,&k);
    for (int i=1;i<=n;i++) {
	for (int j=1;i*j<=n;j++) {
	    LL rx=min(n-i*j,i-1);
	    LL lx=k;	    
	    if (lx<=rx) ans+=rx-lx+1;
	}
    }
    if (!k) k=1;
    for (int i=k;i<=n;i++) ans+=(n-i);
    printf("%lld\n",ans);
    return 0;
}
