#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define LL long long
const int N=105;
const LL mod=1000000007;
int a[N];
LL sqrr(LL x){return x*x%mod;}
LL mi2(int x){
    if (!x) return 1;if (x==1) return 2;
    LL ans=sqrr(mi2(x>>1));
    if (x&1) ans=ans*2%mod;
    return ans;
}
LL dp(int l,int r,int h,int ff){
    if (l>r) return 1ll;
    if (l==r) return mi2(a[l]-h);
    int i,mini=0;
    for (i=l;i<=r;i++) if (a[i]<a[mini]) mini=i;
    if (ff) return dp(l,mini-1,a[mini],ff)*dp(mini+1,r,a[mini],ff)%mod*mi2(a[mini]-h)%mod;
    else{
        LL ans1=dp(l,mini-1,a[mini]-1,0)*dp(mini+1,r,a[mini]-1,0)%mod*2ll%mod;
        LL ans2=dp(l,mini-1,a[mini],1)*dp(mini+1,r,a[mini],1)%mod*(mi2(a[mini]-h)+mod-2)%mod;
        return (ans1+ans2)%mod;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    a[0]=0x7fffffff;
    printf("%lld\n",dp(1,n,0,0));

    return 0;
}
