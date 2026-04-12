#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int cnt = 0;
    rep(i, h) rep(j, w) {
        char a;
        cin >> a;
        if (a == '#') cnt++;
    }

    if (cnt == h + w - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
