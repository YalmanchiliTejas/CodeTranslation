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
    auto it_first_item = m.begin();
    cout << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        cout << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    string s_num;
    range(i, 0, 3) {
        char tmp;
        cin >> tmp;
        s_num.push_back(tmp);
    }
    lint num = stoll(s_num);
    cout << (num % 4 == 0 ? "YES" : "NO") << "\n";
}