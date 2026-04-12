#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;

    int res = x/(y+z);
    if(res*(y+z)+z <= x) cout << res << endl;
    else cout << res-1 << endl;

}