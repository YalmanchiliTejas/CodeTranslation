#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

int main() {
    int n, a, b, c, x;
    while (cin >> n >> a >> b >> c >> x and (n or a or b or c or x)) {

        vector<int> y(n);
        rep(i, n) cin >> y[i];

        int cnt=0, i=0;
        for (i=0; i<=10000 and cnt<n; ++i) {
            if (i) x = (a * x + b) % c;
            if (x == y[cnt] ) {
                cnt++;
            }
            if (cnt == n) {
                break;
            }
        }

        cout << (cnt == n ? i : -1) << endl;

    }
}