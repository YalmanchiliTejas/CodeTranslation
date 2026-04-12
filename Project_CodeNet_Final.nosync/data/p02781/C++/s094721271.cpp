#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Combination {
    Combination(ll n) {
        mNumTbl.resize(n + 1);
        mInverseNumTbl.resize(n + 1);
        mNumTbl[0] = 1;
        mInverseNumTbl[0] = 1;
        FOR(i, n + 1, 1) {
            mNumTbl[i] = (mNumTbl[i - 1] * i) % MOD;
        }
        FOR(i, n + 1, 1) {
            mInverseNumTbl[i] = modpow(mNumTbl[i]);
        }
    }

    ll get(ll n, ll r) {
        if (n < r || n < 0)
            return 0;
        return (((mNumTbl[n] * mInverseNumTbl[r]) % MOD) * mInverseNumTbl[n - r]) % MOD;
    }

    ll modpow(ll n) {
        ll s = 1, p = n;
        for (ll i = 0; (1LL << i) <= MOD - 2; ++i, p = (p * p) % MOD) {
            if (((MOD - 2) & (1 << i)) == 0)
                continue;
            s *= p;
            s %= MOD;
        }
        return s;
    }

    vector<ll> mInverseNumTbl;
    vector<ll> mNumTbl;
};

int main() {
    string N;
    ll K;
    cin >> N >> K;
    ll length = N.length();
    Combination cmb(1000);
    ll ans = 0;
    REP(i, length - 1) {
        //! i+1桁でちょうどK個になるもの
        //! i+1桁目は固定
        ll t = 9;
        if (K - 1 > 0)
            t *= cmb.get(i, K - 1) * pow(9LL, K - 1);
        ans += t;
    }
    //! 最上位桁を考える
    {
        {
            ll t = N[0] - '0' - 1;
            if (K - 1 > 0) {
                t *= cmb.get(length - 1, K - 1) * pow(9LL, K - 1);
            }
            ans += t;
        }
        //! 最上位をN[0]に固定
        if (K - 1 > 0) {
            bool nz = false;
            for (ll b = 1; b < length; ++b) {
                if (nz) {
                    ll t = 9LL;
                    if (K - 2 > 0)
                        t *= cmb.get(length - b - 1, K - 2) * pow(9LL, K - 2);
                    ans += t;
                    continue;
                }

                if (N[b] - '0' == 0)
                    continue;

                {
                    ll t = N[b] - '0' - 1;
                    if (K - 2 > 0) {
                        t *= cmb.get(length - b - 1, K - 2) * pow(9LL, K - 2);
                    }
                    ans += t;

                    //! 固定
                    if (K - 2 > 0) {
                        bool pz = false;
                        for (ll bb = b + 1; bb < length; ++bb) {
                            if (pz) {
                                ans += 9;
                                continue;
                            }
                            if (N[bb] - '0' == 0)
                                continue;
                            ll tt = N[bb] - '0';
                            ans += tt;
                            pz = true;
                        }
                    }
                    else {
                        ans++;
                    }
                }
                nz = true;
            }
        }
        else {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}