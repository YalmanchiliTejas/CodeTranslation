#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,a[51],b[51];

void eat(ll l,ll x){
    if(l==0){
        ans++;
        return;
    }
    if(--x<=0)return;
    if(a[l-1]<x){
        ans+=b[l-1];
        x-=a[l-1];
    }else{
        eat(l-1,x);
        return;
    }
    ans++;
    if(--x<=0)return;
    if(a[l]<x){
        ans+=b[l-1];
        x-=a[l-1];
    }else{
        eat(l-1,x);
        return;
    }
}

int main(){
    ll n,x;
    cin>>n>>x;
    a[0]=1;
    b[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=2*a[i-1]+3;
        b[i]=2*b[i-1]+1;
    }
    ans=0;
    eat(n,x);
    cout<<ans<<endl;
}
