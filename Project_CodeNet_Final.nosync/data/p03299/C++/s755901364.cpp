#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 110;
const int MOD = 1e9+7;

inline int add(int a, int b) { return (a+b)%MOD; }
inline int mul(int a, int b) { return (a*1ll*b)%MOD; }
inline int subt(int a, int b) { a = (a-b)%MOD; return a < 0 ? a+MOD : a; }

int n, H[N];

int pw(int b)
{
    int a = 2, ans = 1;
    while (b) {
        if (b&1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

pii solve(int l, int r, int dh)
{
    int mn = MOD;
    for (int i = l; i <= r; ++i)
        mn = min(mn, H[i]);
    int all = 1, sw = 2;
    for (int i = l; i <= r; ) {
        if (H[i] == mn) {
            all = mul(all, 2);
            ++i;
        } else {
            int j = i;
            while (j <= r && H[j] > mn) ++j;
            pii ret = solve(i, j-1, mn);
            all = mul(all, add( mul(2, ret.second), ret.first ));
            sw = mul(sw, ret.second);
            i = j;
        }
    }
    int nsw = subt(all, sw);
    sw = mul(sw, pw(mn-dh-1));
    return pii(nsw, sw);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &H[i]);
    pii ans = solve(0, n-1, 0);
    printf("%d\n", add(ans.first, ans.second));

    return 0;
}
