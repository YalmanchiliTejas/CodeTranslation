#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007, mod2 = 998244353, inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int cnt[1005], a[10005];
int main()
{
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0, j; i < n; ++i){
        for (j = i; j >= 0; --j){
            if (a[j] > a[i]) break;
            if (j == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
