#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n;
    cin >> n;
    int h[n];
    rep(i, 0, n) cin >> h[i];

    int ans = 1;
    rep(i, 1, n) {
        bool flag = true;
        rep(j, 0, i) {
            if (h[i] < h[j]) flag = false;
        }
        if (flag) ans++;
    }

    cout << ans << endl;
    return 0;
}
