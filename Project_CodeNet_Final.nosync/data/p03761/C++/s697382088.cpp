#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
int gcd(int a, int b);
void prime_map(map<ll, ll> &, ll);

int main() {
    // source
    int n;
    cin >> n;
    string s[n];
    rep(i, n) { cin >> s[i]; }
    int count[26] = {};
    rep(i, 26) { count[i] = pow(10, 9); }

    rep(i, n) {
        int count_temp[26] = {};
        rep(l0, s[i].size()) { count_temp[s[i][l0] - 'a'] += 1; }

        rep(l0, 26) {
            count[l0] = min(count[l0], count_temp[l0]);
            if (count[l0] == pow(10, 9)) {
                count[l0] = 0;
            }
        }
    }

    string ans = "";
    rep(l0, 26) {
        rep(l1, count[l0]) { ans += char('a' + l0); }
    }

    cout << ans << endl;
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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

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
