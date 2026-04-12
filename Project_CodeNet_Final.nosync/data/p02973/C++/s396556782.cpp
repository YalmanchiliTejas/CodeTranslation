#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    multiset<ll> clr;
    rep(i, n) {
        if (sz(clr) == 0) {
            clr.insert(a[i]);
            continue;
        }
        auto it = clr.lower_bound(a[i]);
        if (it == clr.begin()) {
            clr.insert(a[i]);
        }
        else {
            it--;
            clr.erase(it++);
            clr.insert(a[i]);
        }
    }
    cout << sz(clr) << endl;
    return 0;
}
