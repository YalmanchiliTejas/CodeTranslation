#include<stdio.h>

using namespace std;
typedef long long ll;

const int N=55;
ll a[N];
int n;

bool check(){
    for(int i=1;i<=n;i++){
        if(a[i]>=n) return 1;
    }
    return 0;
}

ll cnt[N];
void solve(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);

    ll ans=0;
    while(check()){
        ll tot=0;
        for(int i=1;i<=n;i++){
            cnt[i]=a[i]/n,tot+=cnt[i];
            a[i]%=n;
        }
        ans+=tot;
        for(int i=1;i<=n;i++){
            a[i]+=tot-cnt[i];
        }
    }
    printf("%lld\n",ans);
}

int main(){
    solve();
}
