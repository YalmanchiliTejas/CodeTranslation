#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define tinput int t; cin>>t; while(t--)
#define rep(i,n,s) for((i)=(s); (i)<(n); (i)++)

template <typename T>
T mini(T x, T y) { return (x<y)?x:y; }
template <typename T>
T maxi(T x, T y) { return (x>y)?x:y; }
ll M=1e9+7;

int main(){
  //  freopen("input2.txt", "r", stdin);
  //  freopen("output2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, i;
    cin>>n;
    ll a[n];
    rep(i,n,0) cin>>a[i];
    ll sum[n];
    sum[n-1]=a[n-1];
    for(i=n-2;i>=0;i--) { sum[i]=sum[i+1]+a[i]; }
    ll ans = 0;
    for(i=0;i<n-1;i++) {
        ll x=sum[i+1]%M;
        ll aux=a[i]*x;
        aux=aux%M;
        ans+=aux;
    }
    ans=ans%M;
    cout<<ans;
    return 0;
}