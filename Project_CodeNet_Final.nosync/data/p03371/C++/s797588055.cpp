#include <bits/stdc++.h>
using namespace std;

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vector<vector<t>>;
typedef long long ll;
typedef vc<int> vi;
typedef vvc<int> vvi;
typedef pair<int, int> pi;

#define uset unordered_set
#define umap unordered_map

#define endl "\n"

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()

#define all(a) a.bg, a.ed

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "( " << p.first << ", " << p.second << " )";
}

template <class t>
ostream &operator<<(ostream &os, const vc<t> &v) {
    os << "[ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    return os << " ]";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(18);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution

    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (2 * c < a + b) {
        if (x == y) {
            cout << c * (x + y);
        } else if (x < y) {
            if (2 * c < b) {
                cout << 2 * c * x + 2 * c * (y - x);
            } else {
                cout << 2 * c * x + b * (y - x);
            }
        } else {
            if (2 * c < a) {
                cout << 2 * c * y + 2 * c * (x - y);
            } else {
                cout << 2 * c * y + a * (x - y);
            }
        }
    } else {
        cout << a * x + b * y;
    }
}
