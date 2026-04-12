#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

signed main() {
    ll N;
    cin>>N;
    vector<ll> s(N);
    rep(i,0,N)
        cin>>s[i];

    ll ans = 0;
    // C=A-B
    // k=何度もどりが発生するか
    // A + kC = N-1
    // kc <= N-1
    for (ll C=1; C<N; C++) {
        set<ll> used;
        ll t = 0;
        for (ll k=0; k*C<=N-1; k++) {
            ll A = N-1 - k*C;
            ll B = A - C;
            if (!(0<B && B<A && A<=N-1)) {
                break;
            }
            if (used.find(k*C) != used.end()) {
                break;
            }
            used.insert(k*C);
            if (used.find(N-1-k*C) != used.end()) {
                break;
            }
            used.insert(N-1-k*C);
            t += s[k*C] + s[N-1-k*C];
            // cout<<"C="<<C<<" A="<<A<<" B="<<B<<" t="<<t<<endl;
            ans = max(ans, t);
        }
    }
    cout<<ans<<endl;
    return 0;
}
