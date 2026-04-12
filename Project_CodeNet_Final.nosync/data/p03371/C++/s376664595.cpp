#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    for (int i = 0; (i /2)<= max(x, y); i += 2) {
        int tmp = 0, tmp_a, tmp_b;

        tmp_a = tmp_b  = (i / 2);
        tmp = i * c;
        if (x - tmp_a > 0) tmp += ((x - tmp_a) * a);
        if (y - tmp_b > 0) tmp += ((y - tmp_b) * b);

        if (i == 0) ans = tmp;
        else ans = min(ans, tmp);
    }

    cout << ans << endl;
}