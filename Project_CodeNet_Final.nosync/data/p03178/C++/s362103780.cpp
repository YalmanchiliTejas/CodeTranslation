#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#define ff first
#define ss second
#define M 1000000007
typedef long long int ll;
using namespace std;
ll power(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b%2!=0){
            ans = ((ans)*(a));
        }
        a = ((a)*(a));
        b=b/2;
    }
    return ans;
}
ll add(ll a,ll b){
    ll temp = (a%M + b%M)%M;
    if(temp>M){
        temp=temp-M;
    }
    return temp;
}
vector <vector <vector <ll>>> dp;
ll solve(const vector <ll> &a,ll n,const ll &k,ll sum,ll check){
    if(n==0){
        if((sum%k)==0){
            return 1;
        }
        return 0;
    }
    if(dp[n][sum][check]!=-1){
        return dp[n][sum][check];
    }
    if(n==a.size()){
        ll ans = 0;
        for(ll i=0;i<=a[n-1];i++){
            if(i<a[n-1]){
                ans+=solve(a,n-1,k,(sum+i)%k,0);
            }
            else
                ans+=solve(a,n-1,k,(sum+i)%k,1);
            ans=ans%M;
        }
        return dp[n][sum][check]=ans;
    }
    ll t;
    ll ans = 0;
    if(check==0){
        t=9;
    }
    else
        t = a[n-1];
    for(ll i=0;i<=t;i++){
        if(check && i==t){
            ans+=solve(a,n-1,k,(sum+i)%k,1);
        }
        else
            ans+=solve(a,n-1,k,(sum+i)%k,0);
        ans=ans%M;
    }
    return dp[n][sum][check]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll k;
    cin>>s>>k;
    vector <ll> a;
    for(ll i=0;i<s.length();i++){
        a.push_back(s[i]-'0');
    }
    reverse(a.begin(),a.end());

    ll n = a.size();
    dp.assign(n+1,vector <vector <ll>> (k+1,vector <ll> (2,-1)));
    ll ans = solve(a,n,k,0,0);
    cout<<(ans-1+M)%M<<endl;
    return 0;
}
