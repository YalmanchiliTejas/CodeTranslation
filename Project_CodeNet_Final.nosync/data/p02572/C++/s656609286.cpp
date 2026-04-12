#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,sum=0,summ=0,a[300005];
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n-1){
        summ+=a[n-1-i];
        summ%=mod;
        sum+=(a[n-2-i]*summ)%mod;
        sum%=mod;
    }
    cout<<sum;
}