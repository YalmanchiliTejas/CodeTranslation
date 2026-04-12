#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e15;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    for(int b = k + 1; b <= n; b++){
        int tmp = n / b * (b - k) + max(0LL, n % b - k + 1);
        if(k == 0) tmp--;
        ans += tmp;
    }
    cout << ans << endl;
}