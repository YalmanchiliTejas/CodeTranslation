#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
typedef long long LL;

LL a[maxn];
int pos[maxn];

int main(void)
{
    LL n;
    scanf("%lld",&n);
    memset(pos,-1,sizeof pos);
    LL x,m;
    scanf("%lld%lld",&x,&m);
    a[1]=x;
    pos[x]=1;
    int l,r;
    for(int i=2;i<maxn;i++){
        a[i] = 1ll*a[i-1]*a[i-1]%m;
        if(pos[a[i]]!=-1){
            l=pos[a[i]];
            r=i;
            break;
        }
        pos[a[i]]=i;
    }
    for(int i=2;i<=r;i++) a[i]+=a[i-1];
    if(n<=r) printf("%lld\n",a[n]);
    else{
        LL times = (n-(l-1))/(r-l);
        int mmm = (n-(l-1))%(r-l);
        // printf("%d %d %lld %d\n",l,r,times,mmm);
        LL ans = times*(a[r]-a[l])+a[l-1+mmm];
        printf("%lld\n",ans);
    }
}

