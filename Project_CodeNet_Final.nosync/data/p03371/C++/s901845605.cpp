#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1001001001;
    for(int i = 0; i <= 100000; ++i) {
        int A = max(0,x-i);
        int B = max(0, y-i);
        ans = min(ans, i*(2*c)+(A*a)+(B*b));
    }
    cout << ans << endl;
    return 0;
}