#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    ll n,ans=0;
    cin >> n;
    vector<ll> a(n);
    ll total=0;
    rep(i,n){
        cin >> a[i];
        total+=a[i];
    }
    
    rep(i,n){
        total-=a[i];
        ans+=a[i]*(total%mod)%mod;
        ans=ans%mod;
    }
    
    cout << ans << endl;

    return 0;
}









