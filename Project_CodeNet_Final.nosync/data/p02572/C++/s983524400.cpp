#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n;
    cin>>n;
    ll a[n];for(int i=0;i<n;++i)cin>>a[i];
    ll b[n];
    ll summ=0;
    for(int i=n-1;i>=0;--i){
        summ = (summ + a[i])%mod;
        b[i] = summ;
    }
    ll ans = 0;
    for(int i=0;i<=n-2;++i){
        ans = (ans + a[i]*b[i+1])%mod;
    }
    cout<<ans;










    return 0;
}