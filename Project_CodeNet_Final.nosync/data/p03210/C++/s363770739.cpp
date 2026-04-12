#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int x;
    cin >> x;
    for (auto n : {3, 5, 7}) {
        if (x == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}