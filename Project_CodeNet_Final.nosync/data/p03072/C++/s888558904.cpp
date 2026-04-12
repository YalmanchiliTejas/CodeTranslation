#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

#define pb push_back
#define mp make_pair
#define all(_c) _c.begin(), _c.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int h, mxh;
    cin >> h;
    mxh = h;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        cin >> h;
        if (h >= mxh)
            cnt++;
        mxh = max(mxh, h);
    }

    cout << cnt << '\n';
    return 0;
}
