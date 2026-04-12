#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

template <class T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if(b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for(T &x : vec) {
        is >> x;
    }
    return is;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    vi a(n);
    cin >> a;

    multiset<int> s;
    int ans = 0;
    for(int x : a) {

        // for(int ss : s) {
        //     cout << ss << " ";
        // }
        // cout << endl;

        auto it = s.upper_bound(-x);
        if(it == s.end()) {
            s.insert(-x);
            ans++;
        } else {
            int n = *it;
            int num = s.erase(*it);
            REP(i, num - 1) { s.insert(n); }
            s.insert(-x);
        }
    }

    cout << ans << endl;

    return 0;
}
