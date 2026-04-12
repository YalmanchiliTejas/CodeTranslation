#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;


void _sol(){
    ll n; cin >> n;
    vector<ll> v(n);
    forr(i,n) cin >> v[i];
    ll ans = 0;
    for(int i=n-2;i>=0;i--){
        ans = (ans + v[i]*v[i+1])%mod;
        v[i] = ( v[i] + v[i+1] )%mod;
    }
    cout << ans;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
