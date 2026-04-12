#include "bits/stdc++.h"
using namespace std;
typedef long long li;


template <long long mod>
struct modint {
    long long x;

    modint<mod>(): x(0LL) {}
    modint<mod>(const long long _data) {
        if (_data < 0) {
            x = (_data % mod + mod) % mod;
        } else if (_data >= mod) {
            x = _data % mod;
        } else {
            x = _data;
        }
    }

    bool operator==(const modint<mod>& op) const {
        return x == op.x;
    }

    bool operator!=(const modint<mod>& op) const {
        return !((*this) == op);
    }

    modint<mod> operator-() const {
        if (x == 0) {
            return modint(0);
        }
        return modint(mod - x);
    }

    modint<mod> operator+(const modint<mod>& op) const {
        const long long newdata = x + op.x;
        if (newdata >= mod) {
            return modint<mod>(newdata - mod);
        } else {
            return modint<mod>(newdata);
        }
    }

    modint<mod>& operator+=(const modint<mod>& op) {
        x = (*this + op).x;
        return *this;
    }

    modint<mod> operator-(const modint<mod>& op) const {
        return *this + (-op);
    }

    modint<mod>& operator-=(const modint<mod>& op) {
        x = (*this - op).x;
        return *this;
    }

    modint<mod> operator*(const modint<mod>& op) const {
        return modint<mod>(x * op.x % mod);
    }

    modint<mod>& operator*=(const modint<mod>& op) {
        x = (*this * op).x;
        return *this;
    }

    modint<mod> pow(const long long n) const {
        if (n == 0) {
            return modint<mod>(1);
        }
        modint<mod> sq = pow(n / 2);
        if (n & 1) {
            return (*this) * sq * sq;
        } else {
            return sq * sq;
        }
    }

    modint<mod> inverse() const {
        return pow(mod - 2);
    }

    modint<mod> operator/(const modint<mod>& op) const {
        return (*this) * op.inverse();
    }

    modint<mod>& operator/=(const modint<mod>& op) {
        x = (*this / op).x;
        return *this;
    }

    friend modint<mod> operator/(const long long dividend, const modint<mod>& divisor) {
        return modint<mod>(dividend) / divisor;
    }

    static long long non_ord(long long x) {
        while (x % mod == 0) {
            x /= mod;
        }
        return x;
    }

    // returns n! / mod^(sum(ord(i))
    // normally equals to n!.
    static modint<mod> factorial(const long long n) {
        static vector<modint<mod>> cache(1, 1);
        while (cache.size() <= n) {
            modint<mod> next = cache.back() * non_ord(cache.size());
            cache.push_back(next);
        }
        return cache[n];
    }

    // returns mod^(sum(ord(i)) / n!
    static modint<mod> invfact(const long long n) {
        static vector<modint<mod>> cache(1, 1);

        while (cache.size() <= n) {
            modint<mod> next = cache.back() / non_ord(cache.size());
            cache.push_back(next);
        }
        return cache[n];
    }

    static long long ordfact(const long long n) {
        static vector<long long> cache(1, 0);

        while (cache.size() <= n) {
            long long x = cache.size();
            long long ord_n = 0;
            while (x % mod == 0) {
                x /= mod;
                ord_n++;
            }
            cache.push_back(cache.back() + ord_n);
        }
        return cache[n];
    }

    static modint<mod> combination(const long long n, const long long k) {
        if (k < 0 || n < k) {
            return modint<mod>(0);
        }

        if (ordfact(n) > ordfact(k) + ordfact(n - k)) {
            return modint<mod>(0);
        }

        if (n < 1e7) {
            return factorial(n) * invfact(k) * invfact(n - k);
        }

        modint<mod> ret = 1;
        for (int i = 1; i <= k; ++i) {
            ret = ret * modint<mod>(n - i + 1) / modint<mod>(i);
        }
        return ret;
    }
};

typedef modint<1000000007> mint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    mint sum = 0, sq_sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        li x;
        cin >> x;
        mint mx = x;
        sum += mx;
        sq_sum += mx * mx;
    }
    
    cout << ((sum * sum - sq_sum) / 2).x << endl;

    return 0;
}