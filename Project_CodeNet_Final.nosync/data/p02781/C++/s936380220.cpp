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
    string S; cin >> S;
    lint N = S.size();
    lint K; cin >> K;
    vec<vec<vec<lint>>> dp(N, vec<vec<lint>>(2, vec<lint>(K + 1, 0)));
    dp.at(0).at(false).at(0) = 1;
    dp.at(0).at(false).at(1) = S.at(0) - '0' - 1;
    dp.at(0).at(true).at(1) = 1;
    // range(n, 0, K + 1) cout << dp.at(0).at(false).at(n) << " " << dp.at(0).at(true).at(n) << "\n";
    // cout << "\n";

    range(i, 1, N) {
        lint D = S.at(i) - '0';
        // n = 0
        dp.at(i).at(false).at(0) += dp.at(i - 1).at(false).at(0) + (D == 0 ? 0 : dp.at(i - 1).at(true).at(0));
        dp.at(i).at(true).at(0) += (D == 0 ? dp.at(i - 1).at(true).at(0) : 0);
        // 1 <= n <= K
        range(n, 1, K + 1) {
            // 0
            dp.at(i).at(false).at(n) += dp.at(i - 1).at(false).at(n) + (D == 0 ? 0 : dp.at(i - 1).at(true).at(n));
            dp.at(i).at(true).at(n) += (D == 0 ? dp.at(i - 1).at(true).at(n) : 0);
            // 1 ~ D - 1
            range(d, 1, D) dp.at(i).at(false).at(n) += dp.at(i - 1).at(false).at(n - 1) + dp.at(i - 1).at(true).at(n - 1);
            // D
            if (D > 0) {
                dp.at(i).at(false).at(n) += dp.at(i - 1).at(false).at(n - 1);
                dp.at(i).at(true).at(n) += dp.at(i - 1).at(true).at(n - 1);
            }
            // D + 1 ~ 9
            range(d, D + 1, 9 + 1) dp.at(i).at(false).at(n) += dp.at(i - 1).at(false).at(n - 1);
        }
        // range(n, 0, K + 1) cout << dp.at(i).at(false).at(n) << " " << dp.at(i).at(true).at(n) << "\n";
        // cout << "\n";
    }
    cout << dp.at(N - 1).at(false).at(K) + dp.at(N - 1).at(true).at(K) << "\n";
}