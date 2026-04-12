#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    int n;
    cin >> n;
    int high = 0;
    int ans = 0;
    rep(i,n) {
        int h; cin >> h;
        if (h >= high) ++ans;
        high = max(high, h);
    }
    cout << ans << endl;
    return 0;
}