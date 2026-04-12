#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 4000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
    long long x;
public:
    mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
    mint operator-() const {
        return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }

    mint operator^(const ll& t)const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return pow(MOD - 2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }
};

//////////////////////////

int main() {
    
    ll N;
    cin >> N;
    vector<pair<ll,ll>> a(2 * N + 1);

    repn(i, 2*N) {
        cin >> a[i].first;
        a[i].second = (i + 1) / 2;
    }

    sort(++a.begin(), a.end());

    vector<ll> c(N + 1,-1);
    vector<ll> p(2 * N + 1);
    
    repn(i, 2 * N) {
        if (c[a[i].second] == -1) { c[a[i].second] = i; }
        else {
            p[i] = c[a[i].second];
            p[c[a[i].second]] = i;
        }
    }

    //repn(i, 2 * N)cout << p[i] << endl;

    ll ans = INF;

    ll u = 2 * N;
    repn(i, 2 * N) {
        u = min(u, p[i]);
        if (i + 1 == u) { break; }
    }

    ll v = 1;
    for (ll i = 2 * N; i >= 1; i--) {
        v = max(v, p[i]);
        if (i - 1 == v) { break; }
    }

    ans = min(ans, a[2 * N].first - a[u].first) * (a[v].first - a[1].first);


    ll t = v;
    repn(i, u-1) {
        t = max(t, p[i]);
        if (t == 2 * N) { break; }
        ans = min(ans, (a[2 * N].first - a[1].first) * (a[t].first - a[i + 1].first));
    }

    
    cout << ans;
	system("PAUSE");
}