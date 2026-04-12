#include <bits/stdc++.h>


using namespace std;


using ll = long long;

template<long long M>
class modint {
    public:
        long long a;
        modint(const long long x = 0LL) : a((x % M + M) % M) {}
        long long &value() { return a; }
        modint operator+(const modint rhs) const {
            return modint(*this) += rhs;
        }
        modint operator-(const modint rhs) const {
            return modint(*this) -= rhs;
        }
        modint operator*(const modint rhs) const {
            return modint(*this) *= rhs;
        }
        modint operator/(const modint rhs) const {
            return modint(*this) /= rhs;
        }
        modint &operator+=(const modint rhs) {
            a += rhs.a;
            if (a >= M) {
                a -= M;
            }
            return *this;
        }
        modint &operator-=(const modint rhs) {
            if (a < rhs.a) {
                a += M;
            }
            a -= rhs.a;
            return *this;
        }
        modint &operator*=(const modint rhs) {
            a = a * rhs.a % M;
            return *this;
        }
        modint pow(long long n) const {
            modint ret(1);
            modint x = *this;
            while (n) {
                if ((n & 1) == 1) {
                    ret *= x;
                }
                n >>= 1;
                x *= x;
            }
            return ret;
        }
        modint inv() const {
            return pow(M - 2);
        }
        modint &operator/=(const modint rhs) {
            return *this *= rhs.inv();
        }
};

const long long M = 1000000007;

using mint = modint<M>;


int main(void) {
    ll N;
    cin >> N;
    vector<ll> A(N);
    mint acc = 0;
    mint diag = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        acc += A[i];
        diag += A[i] * A[i];
    }
    mint ans = (acc * acc - diag) / 2;
    cout << ans.a << endl;
}
