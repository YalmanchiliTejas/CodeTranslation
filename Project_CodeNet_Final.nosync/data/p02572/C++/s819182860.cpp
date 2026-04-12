#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    vector<ll> cum(n);
    cum[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        cum[i]=cum[i+1]+A[i];
    }
    ll ans=0;
    ll mod=inf;
    for(int i=0;i<n-1;i++){
        ans+=A[i]*(cum[i+1]%mod);
        ans%=mod;
    }
    cout << ans << endl;
}