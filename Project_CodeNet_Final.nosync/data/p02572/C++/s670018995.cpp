#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a) {
        if((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if(!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if(t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll asum;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        asum += A.at(i);
    }

    mint ans = 0;
    ll s = asum;
    for(int i = 0; i < N - 1; i++) {
        s -= A.at(i);
        ans += mint(s) * A.at(i);
    }
    cout << ans.x << endl;

    return 0;
}