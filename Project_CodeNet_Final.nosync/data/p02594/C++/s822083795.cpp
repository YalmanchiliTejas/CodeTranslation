#include <bits/stdc++.h>

using namespace std;

void solve() {
        int x;
        cin >> x;
        if (x >= 30) cout << "Yes" << endl;
        else cout << "No" << endl;
}


int main() {
#ifdef QWERTY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);


        int t = 1;
//        cin >> t;

        for (int i = 1; i <= t; i++) {
//                cout << "Case #" << i << ':' << endl;
                solve();
        }


        return 0;
}