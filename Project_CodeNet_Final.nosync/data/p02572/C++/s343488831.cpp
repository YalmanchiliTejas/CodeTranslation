
#define INF 10000000000
#define MOD 1000000007

#if 1   // use_templates

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, up) for (ll i = 0; i < (up); ++i)
#define repp(i, up) for (ll i = 0; i <= (up); ++i)
#define rrep(i, lo, up) for (ll i = (lo); i < (up); ++i)
#define rrepp(i, lo, up) for (ll i = (lo); i <= (up); ++i)
#define eep(i, lo, up) for ((i) = (lo); (i) < (up); ++(i))
#define eepp(i, lo, up) for ((i) = (lo); (i) <= (up); ++(i))
#define feach(it, vec) for (auto it = (vec).begin(); it != (vec).end(); ++it)
#define emax(l, r) l = max(l, r)
#define vmin(l, r) l = min(l, r)

template<class T, class U>
bool contains(const T & vec, const U & value) {
    return vec.find(value) != vec.end();
}

ll gcd(ll a, ll b);

ll gcd(ll a, ll b)
{
    if (a < b) {
        return gcd(b, a);
    }
    ll r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

#endif  // end of use_templates

#ifndef TEMPLATE_MOD
#define TEMPLATE_MOD

#include <iostream>

#ifndef MOD
#define MOD 1000000007
#pragma message("using default mod ")
#endif

typedef long long ll;
typedef unsigned long long ull;

template<class T>
constexpr auto my_pow(T a, ll n);

constexpr bool is_prime(ll n) {
    if (n < 2) {
        return false;
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

template<class T, T n>
class mod_t
{
    static_assert(n > 1, "invalid modulus");

    T value;

public:
    constexpr mod_t() : value() { }
    constexpr mod_t(T x) : value(normalize(x)) { }
    constexpr mod_t(const mod_t& x) : value(x.value) { }
    
    explicit constexpr operator T() const {
        return value;
    }
    constexpr auto& operator+=(mod_t<T, n> right) {
        value = (value + right.value) % n;
        return *this;
    }
    constexpr auto& operator++() {
        return *this += mod_t<T, n>(1);
    }
    constexpr auto operator++(int) {
        decltype(*this) tmp(*this);
        *this = *this + mod_t<T, n>(1);
        return tmp;
    }
    constexpr auto& operator-=(mod_t<T, n> right) {
        value = (value - right.value + n) % n;
        return *this;
    }
    constexpr auto& operator--() {
        return *this -= mod_t<T, n>(1);
    }
    constexpr auto operator--(int) {
        decltype(*this) tmp(*this);
        *this = *this - mod_t<T, n>(1);
        return tmp;
    }
    constexpr auto& operator*=(mod_t<T, n> right) {
        value = (value * right.value) % n;
        return *this;
    }
    constexpr auto& operator/=(mod_t<T, n> right) {
        static_assert(is_prime(n), "not a prime");
        return *this = *this * right.pow(n - 2);
    }
    constexpr auto pow(ll nn) const {
        return my_pow(*this, nn);
    }
    constexpr auto inv() const {
        return pow(n - 2);
    }

    static constexpr auto normalize(T x) {
        if (x < 0) {
            return (n + x % n) % n;
        } else {
            return x % n;
        }
    }
};

template<class T, T n>
constexpr auto operator+(mod_t<T, n> left, mod_t<T, n> right) {
    return mod_t<T, n>(left) += right;
}
template<class T, T n>
constexpr auto operator+(mod_t<T, n> left, T right) {
    return mod_t<T, n>(left) += right;
}
template<class T, T n>
constexpr auto operator+(T left, mod_t<T, n> right) {
    return mod_t<T, n>(left) += right;
}
template<class T, T n>
constexpr auto operator-(mod_t<T, n> left, mod_t<T, n> right) {
    return mod_t<T, n>(left) -= right;
}
template<class T, T n>
constexpr auto operator-(mod_t<T, n> left, T right) {
    return mod_t<T, n>(left) -= right;
}
template<class T, T n>
constexpr auto operator-(T left, mod_t<T, n> right) {
    return mod_t<T, n>(left) -= right;
}
template<class T, T n>
constexpr auto operator*(mod_t<T, n> left, mod_t<T, n> right) {
    return mod_t<T, n>(left) *= right;
}
template<class T, T n>
constexpr auto operator*(mod_t<T, n> left, T right) {
    return mod_t<T, n>(left) *= right;
}
template<class T, T n>
constexpr auto operator*(T left, mod_t<T, n> right) {
    return mod_t<T, n>(left) *= right;
}
/*
template<class T, T n>
constexpr auto operator/(mod_t<T, n> left, mod_t<T, n> right) {
    return mod_t<T, n>(left) /= right;
}
template<class T, T n>
constexpr auto operator/(mod_t<T, n> left, T right) {
    return mod_t<T, n>(left) /= right;
}*/
template<class T, T n>
std::istream& operator>>(std::istream& in, mod_t<T, n>& out) {
    T tmp;
    in >> tmp;
    out.value = mod_t<T, n>::normalize(tmp);
    return in;
}
template<class T, T n>
std::ostream& operator<<(std::ostream& out, mod_t<T, n> val) {
    out << (T)val;
    return out;
}
typedef mod_t<ll, MOD> mod;

template<class T>
constexpr auto my_pow(T a, ll n) {
    if (n <= 0) {
        return T(1);
    } else if (n == 1) {
        return T(a);
    } else if (n % 2 == 0) {
        auto work = my_pow(a, n / 2);
        return work * work;
    } else {
        return my_pow(a, n - 1) * a;
    }
}

#endif  // defined(TEMPLATE_MOD)


int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n) {
        cin >> a[i];
    }

    mod s = 0, s2 = 0;
    rep(i, n) {
        s += a[i];
        s2 += a[i] * a[i];
    }
    mod tmp = s * s - s2;
    tmp /= 2;
    cout << tmp << endl;
    return 0;
}
