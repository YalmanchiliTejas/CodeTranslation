#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
    int n;
    cin >> n;
    vec<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i];
        y[i] = x[i];
    }

    sort(x.begin(), x.end());
    int l = x[n / 2 - 1];
    int r = x[n / 2];

    if (l == r) rep(i, n) cout << l << endl;
    else {
        rep(i, n) {
            if (y[i] <= l) cout << r << endl;
            else cout << l << endl;
        }
    }

    return 0;
}
