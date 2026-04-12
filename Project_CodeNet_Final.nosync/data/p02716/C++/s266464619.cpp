#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
ll f[N][3];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            f[i][j]=-1e18;
        }
    }
    for(int i=1;i<=3;i++) {
        f[i][i-1]=a[i];
    }
    f[3][0]=a[1]+a[3];
    for(int i=4;i<=n;i++) {
        f[i][0]=f[i-2][0]+a[i];
        f[i][1]=max(f[i-2][1],f[i-3][0])+a[i];
        f[i][2]=max(f[i-2][2],f[i-3][1])+a[i];
        if(i>4) f[i][2]=max(f[i][2],f[i-4][0]+a[i]);
    }
    ll ans;
    if(n&1) ans=max(f[n][2],max(f[n-1][1],f[n-2][0]));
    else ans=max(f[n][1],f[n-1][0]);
    printf("%lld\n",ans);
    return 0;
}
