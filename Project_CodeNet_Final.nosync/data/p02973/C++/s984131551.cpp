#include<bits/stdc++.h>
#define ll long long
#define inf 10000000000
#define pll pair<ll,ll>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define forn(i,n) for(ll i=1;i<=n;i++)
#define forRn(i,n) for(ll i=n;i>=1;i--)
#define forz(i,n) for(ll i=0;i<n;i++)
#define forRz(i,n) for(ll i=n-1;i>=0;i--)
#define forab(i,a,b) for(ll i=a;i<=b;i++)
#define mod 998244353
#define has 3
ll gcd(ll x,ll y){ return y==0?x:gcd(y,x%y); }
ll lcm(ll x,ll y){ return x/gcd(x,y)*y; }

string le,ri;

int main(void)
{
    magic;
    ll N,sz=0;
    cin>>N;
    ll arr[100005];
    forn(i,N) cin>>arr[i];
    reverse(arr+1,arr+N+1);
    forn(i,N){
        ll p = upper_bound(arr+1,arr+1+sz,arr[i])-arr;
        if(p==sz+1) sz++;
        arr[p] = arr[i];
    }
    cout<<sz;
}
