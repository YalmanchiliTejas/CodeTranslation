#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
const int maxn=20;
const int maxm=2<<16;
const int maxe=maxn*2;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,m,k;


int main(){
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int b=k+1;b<=n;b++){
        ans+=b-max(k,1);
        int num=(n+1-b)/b;
        ans+=num*(b-k);
        int lef=n+1-b-num*b;
        if(lef>=k+1)ans+=lef-k;
    }
    printf("%lld\n",ans);
    return 0;
}
