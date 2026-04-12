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
    vector<ll> A(N + 1);
    repn(i, N) cin >> A[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));

    dp[1][1] = A[1];
    for(ll i=2; i<=N; i++) {
        if (i % 2 == 0) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + A[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + A[i]);
        }
        if (i % 2 == 1) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + A[i]);
            dp[i][1] = dp[i - 2][1] + A[i];
        }
    }

    if (N % 2 == 1) { cout << dp[N][0]; }
    else { cout << dp[N][1]; }

    system("PAUSE");
}