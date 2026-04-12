#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
template <typename Iter, typename T> int gt(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L; }
template <typename Iter, typename T> int ge(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L; }
template <typename Iter, typename T> int lt(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L - 1; }
template <typename Iter, typename T> int le(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L - 1; }
template <typename Bst, typename T> typename Bst::const_iterator gt(const Bst& bst, T v) { return bst.upper_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator ge(const Bst& bst, T v) { return bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator lt(const Bst& bst, T v) { return bst.lower_bound(v) == bst.begin() ? bst.end() : --bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator le(const Bst& bst, T v) { return bst.upper_bound(v) == bst.begin() ? bst.end() : --bst.upper_bound(v); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    multiset<int> s;
    for(int x : a) {
        auto it = lt(s, x);
        if(it != s.end()) {
            s.erase(it);
        }
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
