#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    cout << ((x-z) / (y+z)) << endl;
}

int main() {
    solve();

    return 0;
}
