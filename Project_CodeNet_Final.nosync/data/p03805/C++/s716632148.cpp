#include <bits/stdc++.h>
#define range(i, l, r) for(int (i) = (l); (i) < (r); (i)++)
#define reversed_range(i, l, r) for (int (i) = (r) - 1; (i) >= l; (i)--)
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

bool is_traversable(const vec<lint>& perm, vec<vec<lint>>& adj) {
    lint num_nodes = perm.size();
    range(i, 0, num_nodes - 1) {
        lint node = perm.at(i), next_node = perm.at(i + 1);
        if (find(adj.at(node).begin(), adj.at(node).end(), next_node) == adj.at(node).end())
            return false;
    }
    return true;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    lint N, M;
    cin >> N >> M;
    vec<vec<lint>> adj(N, vec<lint>());
    range(i, 0, M) {
        lint a, b;
        cin >> a >> b;
        a--; b--;
        adj.at(a).emplace_back(b);
        adj.at(b).emplace_back(a);
    }
    vec<lint> perm(N);
    lint num_valid_paths = 0;
    range(i, 0, N) perm.at(i) = i;
    do {
        if (is_traversable(perm, adj)) num_valid_paths += 1;
    } while (next_permutation(perm.begin() + 1, perm.end()));
    cout << num_valid_paths << "\n";
}