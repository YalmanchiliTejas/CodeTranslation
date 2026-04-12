#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0; i<(n); ++i)

map<ll, int> prime_factor(ll n) {
    map<ll, int> mp;
    if (n == 1) {
        // mp[1] = 1;
        return mp;
    }
    ll i = 2;
    while (n > 1) {
        if (n < i * i) {
            mp[n]++;
            return mp;
        }
        if (n % i == 0) {
            n /= i;
            mp[i]++;
        } else {
            i++;
        }
    }
    return mp;
}

signed main() {

    int N;  cin >> N;
    vector<ll> A(N);  REP(i, N) cin >> A[i];

    set<ll> st;
    for (auto& e: A) {
        auto mp = prime_factor(e);
        for (auto& f: mp) {
            st.insert(f.first);
        }
    }

    ll ans = 0;
    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        // cerr << "! : " << *itr << endl;z
        ll sum = 0;
        REP(i, N) {
            if (A[i] % *itr == 0) {
                // cerr << A[i] << ' ' << *itr << endl;
                sum += A[i];
            }
        }
        // cerr << endl;
        ans = max<ll>(ans, sum);
    }

    cout << ans << endl;

}
