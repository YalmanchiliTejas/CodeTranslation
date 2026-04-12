#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    
    int num = 0;
    num = ((r * 100) + (g * 10) + (b * 1));

    if (num % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}