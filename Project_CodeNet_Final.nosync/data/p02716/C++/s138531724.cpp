#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll a[200005] = {}, d[200005][3];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d[0][0] = 0;
    d[0][1] = d[0][2] = d[1][1] = d[1][2] = -1ll * mod * mod;
    d[1][0] = a[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <3; j++) {
            d[i][j] = -1ll * mod * mod;
            for (int k = 0; k <= j; k++) if (i - k - 2 >= 0) {
                d[i][j] = max(d[i][j], d[i - k - 2][j - k] + a[i]);
            }
            //cout << d[i][j] << " \n"[j == 2];
        }
    }
    if (n % 2) cout << max({d[n][2], d[n][1], d[n - 1][1], d[n - 1][0], d[n - 2][0]});
    else cout << max({d[n][0], d[n][1], d[n - 1][0]});
}
