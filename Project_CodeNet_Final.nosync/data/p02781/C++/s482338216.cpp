#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define sz(x) ((int)(x).size())

// Make arbitrary dimensional vector with an initial value
template <class T>
vector<T> create(size_t size, T& initialValue) {
    return vector<T>(size, initialValue);
}

template <class T, class... Args>
auto create(size_t head, Args&&... tail) {
    auto inner = create<T>(tail...);
    return vector<decltype(inner)>(head, inner);
}

// To string overloads
template <typename A, typename B>
string to_string(const pair<A, B>& p);
template <class... Types>
string to_string(tuple<Types...> p);

string to_string(char c) { return (string) "'" + c + "'"; }

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return b ? "true" : "false"; }

string to_string(const vector<bool>& v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < (int)v.size(); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(const bitset<N>& v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += (char)('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(const A& v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class... Types>
string to_string(tuple<Types...> p) {
    string res = "(";
    int sz = tuple_size<decltype(p)>::value;
    apply([&res, &sz](auto&&... args) { ((--sz, res += to_string(args) + (sz ? ", " : "")), ...); }, p);
    res += ")";
    return res;
}

#ifdef LOCAL
#define debug(x...) cerr << "Line " << __LINE__ << ": " << #x << " = " << to_string(x) << endl
#else
#define debug(x...) ((void)42)
#endif

vector<int> n;
int k;
vector<int> pref;

bool isAllZero(int l, int r) {
    if (l > r) {
        return true;
    }
    int sum = pref[r] - ((l == 0) ? 0 : pref[l - 1]);
    return sum == 0;
}

bool bad(int i, int j, int d1, int d2) {
    return i == 0 && (d1 > n[i] || (d1 == n[i] && isAllZero(i + 1, j - 1) && d2 > n[j]));
}

bool bad(int i, int j, int k, int d1, int d2, int d3) {
    return i == 0 && (d1 > n[i] || (d1 == n[i] && isAllZero(i + 1, j - 1) &&
                                    (d2 > n[j] || (d2 == n[j] && isAllZero(j + 1, k - 1) && d3 > n[k]))));
}

void solve() {
    string s;
    cin >> s >> k;

    n = vector<int>(sz(s));
    for (int i = 0; i < sz(n); i++) {
        n[i] = s[i] - '0';
    }

    pref = vector<int>(sz(n));
    pref[0] = n[0];
    for (int i = 1; i < sz(pref); i++) {
        pref[i] = pref[i - 1] + n[i];
    }

    ll ans;
    if (k == 1) {
        ans = (sz(n) - 1) * 9 + n[0];
    } else if (k == 2) {
        ans = 0;
        for (int i = 0; i < sz(n); i++) {
            for (int j = i + 1; j < sz(n); j++) {
                for (int d1 = 1; d1 <= 9; d1++) {
                    for (int d2 = 1; d2 <= 9; d2++) {
                        ans += !bad(i, j, d1, d2);
                    }
                }
            }
        }
    } else {
        ans = 0;
        for (int i = 0; i < sz(n); i++) {
            for (int j = i + 1; j < sz(n); j++) {
                for (int k = j + 1; k < sz(n); k++) {
                    for (int d1 = 1; d1 <= 9; d1++) {
                        for (int d2 = 1; d2 <= 9; d2++) {
                            for (int d3 = 1; d3 <= 9; d3++) {
                                ans += !bad(i, j, k, d1, d2, d3);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(15);

    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return EXIT_SUCCESS;
}