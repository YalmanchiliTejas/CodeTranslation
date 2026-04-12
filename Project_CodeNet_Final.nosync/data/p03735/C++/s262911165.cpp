#include <bits/stdc++.h>
using namespace std;
#define LL long long
multiset <int> S;
const int N = 300000;
const int INF = 1e9;
int mn = INF, mx, n;
LL ans = 1e18;
int xi[N], yi[N], ord[N];
int comp(int a, int b)
{
    if (xi[a] != xi[b]) return xi[a] < xi[b];
    return yi[a] < yi[b];
}
int main()
{
    // freopen("sparse0.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d%d", &xi[i], &yi[i]);
        if (xi[i] > yi[i]) swap(xi[i], yi[i]);
    }
    for (int i = 1; i <= n; ++ i) ord[i] = i;
    sort(ord + 1, ord + n + 1, comp);

    for (int i = 2; i <= n; ++ i) S.insert(xi[ord[i]]); S.insert(yi[ord[1]]);
    for (int i = 1; i <= n; ++ i) mx = max(mx, yi[i]), mn = min(mn, xi[i]);
    for (int i = 2; ; ++ i)
    {
        auto ip = S.begin(), iq = S.end(); iq --;
        ans = min(ans, 1ll * (*iq - *ip) * (mx - mn));
        if (i == n + 1) break;
        S.erase(S.lower_bound(xi[ord[i]]));
        S.insert(yi[ord[i]]);
    }

    int mxa = 0, mxb = 0, mna = INF, mnb = INF;
    for (int i = 1; i <= n; ++ i)
    {
        if (xi[i] > mxa) mxa = xi[i];
        if (xi[i] < mna) mna = xi[i];
        if (yi[i] > mxb) mxb = yi[i];
        if (yi[i] < mnb) mnb = yi[i];
    }
    ans = min(ans, 1ll * (mxa - mna) * (mxb - mnb));
    printf("%lld\n", ans);
}
