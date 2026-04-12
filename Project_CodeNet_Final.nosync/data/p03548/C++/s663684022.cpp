#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int x, y, z;
int main() {
    cin >> x >> y >> z;
    int ans = (x - z) / (y + z);
    cout << ans << endl;
    return 0;
}
