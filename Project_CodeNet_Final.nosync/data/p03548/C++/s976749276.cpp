#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans;
    
    if (x < y) {
        cout << 0 << endl;
        return 0;
    }
    
    x -= z;
    ans = x / (y + z);
    
    cout << ans << endl;
    return 0;
}