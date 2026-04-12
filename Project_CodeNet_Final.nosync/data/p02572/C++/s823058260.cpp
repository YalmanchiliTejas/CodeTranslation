#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    vector<ll> rui(n);
    for(int i = n - 2; i >= 0; i--) {
        rui[i] = (rui[i+1] + a[i+1]) % mod;
    }
    
    ll ans = 0;
    rep(i,n) {
        ans = (ans + a[i] * rui[i]) % mod;
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}


