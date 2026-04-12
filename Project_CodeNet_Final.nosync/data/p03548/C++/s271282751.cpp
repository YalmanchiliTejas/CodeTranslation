#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int x, y, z; cin >> x >> y >> z;
    int tmp = x;
    tmp -= z;
    int ans = 1;
    while (true) {
        tmp -= y + z;
        if (tmp < 0) {
            ans--;
            break;
        }
        else if (tmp == 0) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}