#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int n = (100 * r) + (10 * g) + b;
    cout << (n % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
