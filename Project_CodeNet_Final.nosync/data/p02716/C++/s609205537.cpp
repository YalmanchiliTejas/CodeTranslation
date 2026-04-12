#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
ll inv(ll x){
    return power(x,mod-2);
}
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll a[200010],dp[200010][2],maxdp[200010];
int main(){
    ll i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    ll s1=0,s2=0;
    maxdp[1]=max(a[0],a[1]);
    for(i=0;i<n;i++){
        if(i%2==0)s1+=a[i],dp[i][0]=s1;
        else s2+=a[i],dp[i][1]=s2;
        if((i&1)&&i>1)maxdp[i]=max(dp[i-3][0]+max(a[i],a[i-1]),maxdp[i-2]+a[i]);

    }
    if(n%2==0)cout<<maxdp[n-1];
    else{

        ll ma=maxdp[n-2];
       // cout<<ma<<endl;
        ll sum=a[n-1];
        for(i=n-3;i>=2;i-=2){
            ma=max(ma,sum+maxdp[i-1]);
            sum+=a[i];
        }
        cout<<max(ma,sum);
    }

}
