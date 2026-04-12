#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55],sum,k,n;
void big(){
    ll mx=-1,pos=-1;
    for(ll i=1;i<=n;i++)if(a[i]>mx)mx=a[i],pos=i;
    ll val = mx/n;
    sum=0;
    for(ll i=1;i<=n;i++){
        a[i]+=(i==pos)?-n*val:val;
        sum+=a[i];
    }
    k+=val;
}
void small(){
    while(1){
        ll mx=-1,pos=-1;
        for(ll i=1;i<=n;i++)if(a[i]>mx)mx=a[i],pos=i;
        if(mx<n)return;
        for(ll i=1;i<=n;i++)a[i]+=(i==pos)?-n:1;
        k++;
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    while(sum>1e5)big();
    small();
    cout<<k;
}