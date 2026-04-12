#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long ;

int main(){
    int n; cin >> n;
    vector<ll> a(n),asum(n);
    ll mod = 1000000007 ,sum = 0,ans = 0;
    for(int ix=0;ix<n;ix++){
        cin >> a.at(ix);
    }
    for(int ix=n-1;ix>0;ix--){
        sum += a.at(ix);
        sum %= mod;
        asum.at(ix-1) = sum;
    }
    asum.at(n-1) = 0;
    for(int ix=0;ix<n;ix++){
        ans += a.at(ix)*asum.at(ix);
        ans %= mod;
    }
    cout << ans << endl;
}