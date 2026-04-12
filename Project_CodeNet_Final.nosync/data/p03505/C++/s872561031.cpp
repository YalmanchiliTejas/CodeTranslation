#include <bits/stdc++.h>
using namespace std;
typedef long long cc;
typedef pair <int, int> pii;
#define X first
#define Y second
#define pb push_back
cc k, a, b;
int main() {
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    //freopen("VOI08LOCO.inp", "r", stdin);
    //freopen("VOI08LOCO.out", "w", stdout);
    ios_base  :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> a >> b;
    if (a >= k) cout << 1;
    else {
        if (a <= b) cout << -1;
        else {
            k -= a;
            cout << 2ll * (k / (a - b) + (k % (a - b) != 0)) + 1;
        }
    }
    return 0;
}
