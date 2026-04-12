#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using mii = map<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using tpi = tuple<int, int, int>;

using vqi = vector<queue<int>>;
using vpi = vector<pii>;
using bs = bitset<60>;
using vbi = vector<bs>;

ll gcd(ll a, ll b) {
    if (a < b) {
        swap(a, b);
    }

    /* ユークリッドの互除法 */
    ll r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

constexpr int64_t __pow_mod(int64_t n, int64_t p, int64_t mod) noexcept {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int64_t t = __pow_mod(n, p / 2, mod);
        return (t * t) % mod;
    }
    return (n * (__pow_mod(n, p - 1, mod) % mod)) % mod;
}

constexpr int64_t pow_mod(int64_t n, int64_t p, int64_t mod) noexcept {
    int64_t res = __pow_mod(n, p, mod);
    if (res == 0) {
        res = mod;
    }
    return res;
}

constexpr int64_t nCr_mod(int64_t n, int64_t r, int64_t mod) noexcept {
    int64_t count = 1;
    auto a = r;
    for (auto i = n; i > n - r; i--) {
        count *= i;
        if (count % mod != 0) {
            count %= mod;
        }
        int64_t inv = pow_mod(a, mod - 2, mod);
        count *= inv;
        if (count % mod != 0) {
            count %= mod;
        }
        a--;
    }
    return count;
}

const string YES = "Yes";
const string NO = "No";

void solve(std::string S) {
    if (S[0] == S[1] && S[1] == S[2]) {
        cout << NO << endl;
    } else {
        cout << YES << endl;
    }
}

int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
