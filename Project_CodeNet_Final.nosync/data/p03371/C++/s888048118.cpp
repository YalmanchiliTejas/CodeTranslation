#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

int a,b,c,x,y;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int n = a * x + b * y;

    int m = 2 * c * max(x, y);

    int p = x < y ? b : a;
    int q = 2 * c * min(x, y) + p * abs(x - y);
  
    int ans = min(n, min(m, q));
    cout << ans << endl;
}