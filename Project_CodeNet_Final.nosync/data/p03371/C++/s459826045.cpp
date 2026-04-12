#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int res = a*x + b*y;
    rep1(i, max(x, y)+1){
        int ab = i*2;
        int cand = c*ab + a*max(0, x-i) + b*max(0, y-i);

        res = min(res, cand);
    }

    cout << res << endl;

}