#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int sum(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}
int mul(int a, int b) {
    return (1LL*a*b)%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    int pre = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans = sum(ans, mul(pre, x));
        pre = sum(pre, x);
    }


    cout << ans << "\n";

    return 0;
}
