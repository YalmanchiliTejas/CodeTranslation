#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
#define trav(e, x) for (auto &e : x)
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
//#define int long long
using namespace std;
using ii = pair<int, int>;

signed main() {
    FAST_IO;
    //setIO("input.txt", "output.txt");

    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No");
}
