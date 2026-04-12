#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;
    cout << (x-z)/(y+z) << endl;

    return 0;
}




