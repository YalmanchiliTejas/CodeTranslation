#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+100;
ll f[N],g[N],h[N]; int a[N],n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=2;i<=n;i+=2){
        f[i]=f[i-2]+a[i-1];
        g[i]=max(f[i-2],g[i-2])+a[i];
    }
    if(n&1){
        for(int i=3;i<=n;i+=2){
            h[i]=max(h[i-2]+a[i],max(f[i-1],g[i-1]));
        }printf("%lld\n",h[n]);
    }else printf("%lld\n",max(f[n],g[n]));
}