#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int p = r * 100 + g * 10 + b;
    cout << (((p % 4) == 0) ? "YES" : "NO") << endl;
    return 0;
}