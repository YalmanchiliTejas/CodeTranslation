#include <bits/stdc++.h>
#define range(i, l, r) for(long long int (i) = (l); (i) < (r); (i)++)
#define reversed_range(i, l, r) for (long long int (i) = (r) - 1; (i) >= l; (i)--)
using namespace std;
template <typename T>
using vec = vector<T>;
using lint = long long;
using ulint = unsigned long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;

template <typename S, typename T>
ostream& operator <<(ostream& os, pair<S, T> p) {
    os << "(";
    os << p.first << ", " << p.second;
    return os << ")";
}

template <typename T>
ostream& operator <<(ostream& os, vec<T> v) {
    os << "[";
    if (v.size() == 0) return os << "]";
    for (int i = 0; i < v.size() - 1; i++) {
        os << v.at(i) << ", ";
    }
    return os << v.at(v.size() - 1) << "]";
}

template <typename T>
ostream& operator <<(ostream& os, set<T>& s) {
    os << "{";
    if (s.begin() == s.end()) return os << "}";
    auto it_first_item = s.begin();
    os << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        os << ", " << *it;
    }
    return os << "}";
}

template <typename T>
ostream& operator <<(ostream& os, unordered_set<T>& s) {
    os << "{";
    if (s.begin() == s.end()) return os << "}";
    auto it_first_item = s.begin();
    os << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        os << ", " << *it;
    }
    return os << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, map<K, V> m) {
    os << "{";
    if (m.begin() == m.end()) return os << "}";
    auto it_first_item = m.begin();
    os << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        os << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, unordered_map<K, V> m) {
    os << "{";
    if (m.begin() == m.end()) return os << "}";
    auto it_first_item = m.begin();
    os << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        os << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

lint pow(lint num, lint e, lint MOD) {
    lint res = 1;
    lint cur_num = num;
    while (e) {
        if (e & 1) {
            res *= cur_num;
            res %= MOD;
        }
        cur_num *= cur_num;
        cur_num %= MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    string N; lint K; cin >> N >> K;
    lint dp[N.size()][10][4][2];
    memset(dp, 0, sizeof(dp));
    // range(i, 0, N.size()) range(d, 0, 10) range(n, 0, 4) range(b, 0, 2) assert(dp[i][d][n][b] == 0);

    lint first_digit = N.at(0) - '0';
    // cout << first_digit << "\n";

    dp[0][0][0][0] = 1;
    range(d, 1, first_digit) dp[0][d][1][0] = 1;
    dp[0][first_digit][1][1] = 1;
    range(i, 1, N.size()) {
        lint digit = N.at(i) - '0';
        // cout << digit << "\n";
        range(d, 0, 10) {
            lint nonzero_appeared = d > 0;
            range(pd, 0, 10) range(n, 0, 4) {
                if (n - nonzero_appeared == -1) continue;
                assert(i - 1 >= 0 && n - nonzero_appeared >= 0 && n - nonzero_appeared <= 3);
                dp[i][d][n][0] += dp[i - 1][pd][n - nonzero_appeared][0] + (d < digit ? dp[i - 1][pd][n - nonzero_appeared][1] : 0);
                dp[i][d][n][1] += (d == digit ? dp[i - 1][pd][n - nonzero_appeared][1] : 0);
            }
        }
        // range(d, 0, 10) cout << dp[i][d][3][0] << " ";
        // cout << "\n";
    }
    lint res = 0;
    range(d, 0, 10) res += dp[N.size() - 1][d][K][0] + dp[N.size() - 1][d][K][1];
    cout << res << "\n";
}
