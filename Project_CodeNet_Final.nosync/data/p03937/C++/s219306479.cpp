#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h) {
        string a;
        cin >> a;
        rep(j, w) {
            if(a[j] == '#') cnt++;
        }
    }
    if(cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
