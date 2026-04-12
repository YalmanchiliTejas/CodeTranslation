#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
int main() {
  
  ll int n;
  cin>>n;
  ll int a[n];
  ll sum = 0;
    for(ll int i=0;i<n;i++)
   {
        cin>>a[i];
        sum =(sum%mod +a[i]%mod)%mod;
    } 
    ll dp[n]={0};
    dp[0]=sum-a[0];
    for(int i=1;i<n;i++)
    dp[i] = dp[i-1]%mod-a[i]%mod;
    ll tt =0 ;
    for(int i=0;i<n;i++)
    {
        tt = (tt%mod+ (dp[i]%mod*a[i])%mod+mod)%mod;
    }
    cout<<tt%mod<<endl;



}
