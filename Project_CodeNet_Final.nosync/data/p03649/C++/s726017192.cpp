#define _GLIBCXX_DEBUG
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
    cout << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        cout << ", " << *it;
    }
    return cout << "}";
}

template <typename T>
ostream& operator <<(ostream& os, unordered_set<T>& s) {
    os << "{";
    if (s.begin() == s.end()) return os << "}";
    auto it_first_item = s.begin();
    cout << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        cout << ", " << *it;
    }
    return cout << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, map<K, V> m) {
    os << "{";
    if (m.begin() == m.end()) return os << "}";
    auto it_first_item = m.begin();
    cout << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        cout << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, unordered_map<K, V> m) {
    os << "{";
    if (m.begin() == m.end()) return os << "}";
    auto it_first_item = m.begin();
    cout << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        cout << ", " << it->first << ": " << it->second;
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
    lint N; cin >> N;
    vec<lint> a_list(N), min_num_op(N);
    range(i, 0, N) cin >> a_list.at(i);
    lint res = 0;
    // lint round = 0;
    while (any_of(a_list.begin(), a_list.end(), [&](const lint& a) {return a > N - 1;})) {
        lint total_num_op = 0;
        range(i, 0, N) {
            const lint a = a_list.at(i);
            if (a > N - 1) {
                min_num_op.at(i) = a / N;
                total_num_op += min_num_op.at(i);
            } else min_num_op.at(i) = 0;
        }
        res += total_num_op;
        range(i, 0, N) {
            a_list.at(i) = a_list.at(i) - N * min_num_op.at(i) + (total_num_op - min_num_op.at(i));
        }
        // if (round < 250) cout << a_list << "\n";
        // round++;
    }
    cout << res << "\n";
}