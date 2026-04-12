#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    if (a+b <= 2*c) {
        cout << x*a + y*b << endl;
        return 0;
    }

    int ans = 2 * c * min(x,y);
    if (x <= y) {
        if (b <= 2*c) {
            ans += (y-x) * b;
        }
        else {
            ans += (y-x) * 2 * c;
        }
        cout << ans << endl;
        return 0;
    }

    if (a <= 2*c) {
        ans += (x-y) * a;
    }
    else {
        ans += (x-y) * 2 * c;
    }
    cout << ans << endl;
    return 0;
}