#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k == 0) {
        cout << 1LL * n * n;
        return 0;
    }
    ll ans = 0;
    for(int b = k + 1; b <= n; b++) {
        for(int val = 0; val <= n; val += b) {
            // val = a - r
            // k <= r < b
            // a - b < val <= a - k
            // a < val + b
            // a >= val + k
            ans += min(val + b - 1, n) - min(n + 1, val + k) + 1;
        }
        //printf("%d %d\n" ,b,ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
