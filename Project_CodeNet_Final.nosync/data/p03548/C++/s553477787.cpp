// ybmj
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

int main() {
    /*
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    */
    std::ios::sync_with_stdio(false);
    int x, y, z;
    while (cin >> x >> y >> z) {
        x -= z;
        cout << x / (y + z) << endl;
    }
}
