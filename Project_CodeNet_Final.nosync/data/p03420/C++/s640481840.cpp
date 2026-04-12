#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int n, k;
ll ans = 0;

int main() {
    cin >> n >> k;
    for (int x = k; x < n; x++) {
        int t = n-x;
        for (int b = x+1; b <= n;) {
            int nxt = 0;
            if (t/b) nxt = t/(t/b);
            else nxt = n;
            ans += 1ll*(nxt-b+1)*((t/b)+(x>0));
            b = nxt+1;
        }
    }
    cout << ans << endl;
    return 0;
}
