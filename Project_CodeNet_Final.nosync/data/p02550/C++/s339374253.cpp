#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;

void Main()
{
    ll n, X, M;
    cin >> n >> X >> M;

    vector<ll> Xpow;
    unordered_set<ll> Xs;
    Xpow.push_back(X);
    Xs.emplace(X);
    ll start = 0;
    repi(i, M + 1) {
        ll v = (Xpow[i-1] * Xpow[i-1]) % M;
        if (Xs.find(v) != Xs.end()) {
            auto it = find(all(Xpow), v);
            start = it - Xpow.begin();
            break;
        }
        Xpow.push_back(v);
        Xs.emplace(v);
    }

    ll loopLen = Xpow.size() - start;
    if (n <= start) {
        ll res = accumulate(Xpow.begin(), Xpow.begin() + n, 0LL);
        put(res);
        return;
    }

    ll res = accumulate(Xpow.begin(), Xpow.begin() + start, 0LL);

    ll loopSum = 0;
    for (ll i = start; i < start + loopLen; i++) {
        loopSum += Xpow[i];
    }

    res += loopSum * ((n - start) / loopLen);

    for (ll i = start; i < start + ((n - start) % loopLen); i++) {
        res += Xpow[i];
    }

    put(res);
}
signed main(){ Main();return 0;}