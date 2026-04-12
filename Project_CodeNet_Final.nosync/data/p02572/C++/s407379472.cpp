#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 1000000007
#define ll long long
using namespace std;

int main(){
    ll n; cin>>n;
    ll a[n];
    ll sum[n];
    sum[0]=0;
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=1; i<n; i++){
        sum[i]=sum[i-1]+a[n-i];
        sum[i]%=N;
    }
    
    ll ans=0;
    
    for(ll i=0; i<n-1; i++){
        ll p=a[i]*sum[n-i-1];
        p%=N;
        ans+=p;
        ans%=N;
    }
    
    cout<<ans<<endl;
}