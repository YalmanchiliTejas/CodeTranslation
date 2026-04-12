#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp <<" "<<
bool isprime(ll n){
    if (n <= 1)return false;ll g=sqrt(n);
    for (ll i = 2; i <= g; i++)if (n % i == 0)return false;
    return true;
}
ll MOD=1e9+7;
ll power(ll base, ll exp)
{
    if(exp==1)return base;
    else{if(exp%2==0){ll base1=(pow(power(base, exp/2),2));return base1%MOD;}
        else{ll ans=(base*pow(power(base,(exp-1)/2),2));return ans%MOD;}}
}
ll temp,temp1,temp2;
int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n,sum=0,res=0;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(ll i=0;i<n;i++)
    {
        sum-=a[i];
        res+=((a[i]%MOD)*(sum%MOD))%MOD;
        res%=MOD;
    }
    res%=MOD;
    cout<<res;
    
    return 0;
}