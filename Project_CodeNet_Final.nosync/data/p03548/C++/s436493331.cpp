#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)

using namespace std;

namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

using ll = long long;
ll mod = pow(10, 9) + 7;

template <typename T> void output(T, ll);
ll gcd(ll, ll);
ll lcm(ll, ll);
Bint comb(Bint, Bint);
void prime_map(map<ll, ll> &, ll);

int main() {
    // source
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;
    return 0;
}

Bint comb(Bint a, Bint b) {
    Bint ans = 1;

    if (a < b) {
        return 0;
    }

    rep(i, b) {
        ans *= a - i;
        ans /= i + 1;
    }

    return ans;
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

template <typename T> T min(T a, T b) {

    if (a < b) {
        return a;
    } else {
        return b;
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

void prime_map(map<ll, ll> &m, ll num) {

    if (num == 1) {
        return;
    }
    ll cache = num;
    repd(i, 2, sqrt(num) + 2) {
        if (num % i == 0) {
            if (m[i] == 0) {
                m[i] = 1;
            } else {
                m[i]++;
            }

            num /= i;
            break;
        }
    }
    if (cache == num) {
        if (m[num] == 0) {
            m[num] = 1;
        } else {
            m[num]++;
        }

        return;
    }
    prime_map(m, num);
    return;
}
