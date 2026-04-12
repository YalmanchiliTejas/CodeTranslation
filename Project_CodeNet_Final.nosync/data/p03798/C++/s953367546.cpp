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
    lint N;
    string s;
    cin >> N >> s;
    // assume that 0, 1 are filled
    auto fill = [&](string& animal) {
        range(i, 1, N - 1) {
            char left = animal.at(i - 1);
            char cur = animal.at(i);
            char remark = s.at(i);
            if (left == 'S' and cur == 'S') animal.at(i + 1) = remark == 'o' ? 'S' : 'W';
            else if (left == 'S' and cur == 'W') animal.at(i + 1) = remark == 'o' ? 'W' : 'S';
            else if (left == 'W' and cur == 'S') animal.at(i + 1) = remark == 'o' ? 'W' : 'S';
            else animal.at(i + 1) = remark == 'o' ? 'S' : 'W';  // 'W', 'W'
        }
    };
    auto satisfy = [&](string& animal, lint idx) {
        char remark = s.at(idx);
        char cur = animal.at(idx);
        char left = animal.at(idx == 0 ? N - 1 : idx - 1);
        char right = animal.at(idx == N - 1 ? 0 : idx + 1);
        if (cur == 'S' and remark == 'o') return left == right;
        else if (cur == 'S' and remark == 'x') return left != right;
        else if (cur == 'W' and remark == 'o') return left != right;
        else return left == right;
    };
    string animal(N, ' ');
    vec<pair<char, char>> cur_and_right = {{'S', 'S'}, {'S', 'W'}, {'W', 'S'}, {'W', 'W'}};
    for (const auto& p : cur_and_right) {
        char cur, right; tie(cur, right) = p;
        animal.at(0) = cur, animal.at(1) = right;
        fill(animal);
        if (satisfy(animal, N - 1) and satisfy(animal, 0)) {
            cout << animal << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}