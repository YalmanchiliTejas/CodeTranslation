#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(void){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    
    
    vector<ll> v(n+1,0);
    v[0] = a[0];
    for(int i = 1;i < n;i++)v[i] = v[i-1] + a[i];
    
    ll mod = 1e9+7,ans = 0;
    for(int i = 0;i < n;i++){
        ll num = v[n-1] - v[i];
        //cout << num * a[i] << endl;
        num %= mod;
        ans += ((num * a[i] + mod) % mod);
        ans %= mod;
    }
    cout << ans << endl;
    
}