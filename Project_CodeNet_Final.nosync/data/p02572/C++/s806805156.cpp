#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define ff first
#define ss second
#define forr(i,a,n) for(ll i=a;i<n;i++)
#define ford(i,a,n) for(ll i=n-1;i>=a;i--)
#define all(v) v.begin(),v.end()
#define testc  ll ts;\
               cin>>ts;\
               while(ts--)
#define arn ll n;\
            cin>>n;\
            ll a[n];\
            forr(i,0,n)cin>>a[i];\
               
#define arr(a,n) ll a[n];\
                 forr(i,0,n)cin>>a[i];\
 
#define sss <<" "<<
#define nnn <<"\n"
#define nl cout<<"\n";
#define prtitr(v) for(auto itr=v.begin(); itr!=v.end() ; itr++)cout<<*itr<<" ";
#define fitr(v) for(auto itr=v.begin(); itr!=v.end() ; itr++)
using namespace std;
ll M=1e9+7;
ll cdiv(ll a,ll b){
    return (a%b==0)?a/b:a/b+1;
}
ll myMod(ll a, ll b){
    ll r = a % b;
    return r < 0 ? r + b : r;
}
ll ModPow(ll a,ll b,ll M)
{
    if(M==1)return 0;
    a%=M;
    ll ans=1,t=1;
    while(t>0&&t<=b)
    {
        if(t&b)
        {
            ans*=a;
            ans%=M;
        }
        t<<=1;
        a*=a;
        a%=M;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arn;
    ll sum=0;
    forr(i,0,n)sum+=a[i];
    ll prf[n+1];
    prf[0]=0;
    forr(i,1,n+1)prf[i]=prf[i-1]+a[i-1];
    ll ans=0;
    forr(i,0,n){
        ans=(ans+(a[i]*((prf[n]-prf[i+1])%M))%M)%M;
    }
    cout<<ans;
    return 0;
} 