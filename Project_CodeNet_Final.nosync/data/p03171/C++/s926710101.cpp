#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mN = 3113;
const LL oo = 1e18;
LL a[mN], f[mN][mN][2];

void update(LL &var, LL val, int opt) {
    if (opt) var = max(var, val);
    else var = min(var, val);
}

LL dp(int l, int r, const LL t) {
    if (f[l][r][t] != -oo) return f[l][r][t];
    if (l == r) return f[l][r][t] = t * a[l];
    LL ans = oo;
    if (t) ans *= -1LL;
    update(ans, dp(l+1, r, 1-t) + t*a[l], t);
    update(ans, dp(l, r-1, 1-t) + t*a[r], t);
    //cerr << "f[" << l << "][" << r << "][" << t << "] = " << ans << "\n";
    return f[l][r][t] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
    cin >> n;
    LL sum = 0;
    for (int i=1; i<=n; i++) cin >> a[i], sum += a[i];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            f[i][j][0] = f[i][j][1] = -oo;
    LL taro_point = dp(1,n, 1LL);
    LL jiro_point = sum - taro_point;
    cout << taro_point - jiro_point;
    return 0;
}
