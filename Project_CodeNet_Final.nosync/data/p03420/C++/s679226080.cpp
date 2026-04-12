#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i=1; i <= n; i++){
        int ex = 1;
        while (true){
            int A = i*(ex-1) + k;
            int B = i*ex - 1;
            A = max((int) 1, A);
            B = min(n, B);
            if (A > n) break;
            if (A <= B) ans += B-A+1;
            ex++;
        }
    }
    cout << ans << endl;
    return 0;
}
