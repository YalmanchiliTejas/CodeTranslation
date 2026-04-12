#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;

signed main(){
    double r1, r2, r3;
    cin >> r1 >> r2;
    r3 = r1 * r2 / (r1 + r2);
    printf("%.10f\n", r3);
}