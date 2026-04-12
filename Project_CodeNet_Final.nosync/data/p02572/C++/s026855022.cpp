#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

class Mint
{
private:
    ll x;
public:
    Mint(ll x = 0) :x((x% mod + mod) % mod) {}
    ll Get() const { return x; }
    Mint operator-() const { return Mint(-x); }
    Mint& operator+=(const Mint a)
    {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(const Mint a)
    {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator*=(const Mint a) { (x *= a.x) %= mod; return *this; }
    Mint operator+(const Mint a) const { return Mint(*this) += a; }
    Mint operator-(const Mint a) const { return Mint(*this) -= a; }
    Mint operator*(const Mint a) const { return Mint(*this) *= a; }
    Mint pow(ll t) const
    {
        if (!t) return 1;
        Mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    Mint inv() const { return pow(mod - 2); }
    Mint& operator/=(const Mint a) { return *this *= a.inv(); }
    Mint operator/(const Mint a) const { return Mint(*this) /= a; }
};
inline ostream& operator<<(ostream& os, const Mint& a) { return os << a.Get(); }

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<Mint> s(n);
	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i];
	}

    Mint ans = Mint();
	for (ll i = 0; i < n - 1; i++) {
        ans += Mint(a[i]) * (s[n - 1] - s[i]);
	}
	cout << ans << endl;
}
