#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;

int main() {
    int X;
    cin >> X;
    if (X == 3 || X == 5 || X == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}