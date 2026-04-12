#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
ll mod = pow(10, 9) + 7;

template <typename T> void output(T, ll);
ll gcd(ll, ll);
ll lcm(ll, ll);
void prime_map(map<ll, ll> &, ll);

int main() {
    // source
    int r, g, b;
    cin >> r >> g >> b;
    int ans = 100 * r + 10 * g + b;
    if (ans % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
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
    } else {
        prime_map(m, num);
    }
}
