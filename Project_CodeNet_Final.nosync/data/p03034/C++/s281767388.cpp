#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;

int n;
ll s[100000];

int main() {
    cin >> n;
    rep(i,n) cin >> s[i];
    ll ans = 0;
    for (int c = 1; c <= n-1; c++) {
        ll cnt = 0;
        set<int> hoge;
        for (int k = 0; k*c < n-1; k++) {
            cnt += s[k*c] + s[n-1-k*c];
            if (hoge.count(k*c)) break;
            hoge.insert(k*c);
            if (hoge.count(n-1-k*c)) break;
            hoge.insert(n-1-k*c);
            if (c < n-1-k*c) {
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}
