#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(ll i=a;i<n;i++)
#define w(_t) ll _t;cin>>_t;while(_t--)
ll md=1000000007;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];
    ll ans=0,sm=a[0];
    f(i,1,n){
        ans+=(a[i]*sm)%md;
        ans%=md;
        sm+=a[i];
        sm%=md;
    }
    cout<<ans;
    return 0;
}