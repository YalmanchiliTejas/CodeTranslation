#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    if(k == 0){
        cout << n*n << endl;
        return 0;
    }
    
    ll res = 0;
    for(ll i = k+1; i <= n; ++i){
        res += ((n+1)/i)*(i-k) + max(0LL, ((n+1)%i - k));
        if(k==0) res -= (n+1)/i;
    }

    cout << res << endl;

    return 0;
}