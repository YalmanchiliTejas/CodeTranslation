#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=51;
int n;
ll a[max_n];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    ll ans=0;
    while(1){
        ll res=0;
        for(int i=1;i<=n;i++){
            ll x=(a[i]+res)/n;
            res+=x;
            a[i]-=x*(n+1);
        }
        for(int i=1;i<=n;i++)a[i]+=res;
        if(res==0)break;
        ans+=res;
    }
    printf("%lld\n",ans);
    return 0;
}