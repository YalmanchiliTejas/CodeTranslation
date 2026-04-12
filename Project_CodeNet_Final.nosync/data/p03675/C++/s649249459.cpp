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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> d;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if((n ^ i) % 2) {
            d.push_front(ai);
        } else {
            d.push_back(ai);
        }
    }
    for(int x : d) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}