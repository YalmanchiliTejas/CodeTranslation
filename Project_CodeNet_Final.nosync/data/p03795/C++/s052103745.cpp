#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int x, y;
    x = n * 800;
    y = (n / 15) * 200;
    cout << x - y << endl;
    return 0;
}