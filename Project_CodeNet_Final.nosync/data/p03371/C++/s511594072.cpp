//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int x, y;
    ll a, b, c;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    c = min(c, a+b);
    ll ans;
    if(x > y) {
        ans = y * c;
        x -= y;
    } else {
        ans = x * c;
        x = y-x;
        a = b;
    }


    ans += x * min(a, c);
    cout << ans << endl;
}