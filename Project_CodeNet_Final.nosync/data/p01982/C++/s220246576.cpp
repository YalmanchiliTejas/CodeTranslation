#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    while(1) {
        ll n, l, r;
        cin >> n >> l >> r;
        if(!n) break;
        vector<ll> a(n);
        for(auto &e: a) cin >> e;

        ll res = 0;
        for(ll k=l; k<=r; k++) {
            ll i;
            for(i=0; i<n; i++)
                if(k % a[i] == 0) break;
            res += ~i&1;
        }
        cout << res << endl;
    }
}

