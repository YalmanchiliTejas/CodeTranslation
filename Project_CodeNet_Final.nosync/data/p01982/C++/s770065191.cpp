#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define out(a) cout << a << endl
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)


int main() {
    int n;
    while (cin >> n && n) {
        int l, r; cin >> l >> r;
        int a[n]; rep(i, n) cin >> a[i];
        int cnt = 0;
        rep3(x, l, r + 1) {
            int tmp = inf; int key = -1;
            rep(i, n) {
                if (x % a[i] == 0) {
                    if (tmp > a[i]) {
                        tmp = a[i];
                        key = i + 1;
                        break;
                    }
                }
            }
            if (tmp == inf) {
                if (n % 2 == 0) {
                    cnt++;
                    //out(x);
                }
            } else {
                if (key % 2 == 1) {
                    cnt++;
                    //out(x << " " << key);
                }
            }
        }
        out(cnt);
    }
}


