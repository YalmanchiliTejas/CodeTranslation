#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e17;
int n;
ll a[55], ans, ma, mi;
bool check()
{
    for (int i = 0; i < n; i++) {
        if (a[i] >= n) return false;
    }
    return true;
}
int max_id()
{
    ll ma = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > ma) {
            ma = a[i];
            maxi = i;
        }
    }
    return maxi;
}
int min_id()
{
    ll mi = INF;
    int mini = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < mi) {
            mi = a[i];
            mini = i;
        }
    }
    return mini;
}
int main()
{
    scanf("%d", &n);
    ma = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    if (ma < n * (n + 1)) {
        while (!check()) {
            int t = max_id();
            for (int i = 0; i < n; i++) {
                if (i != t) a[i]++;
                else a[i] -= n;
            }
            ans++;
        }
        printf("%lld\n", ans);
    }
    else {
        int t1 = max_id(), t2 = min_id();
        while (a[t1] - a[t2] > 100) {
            //printf("max: a[%d] = %lld, min: a[%d] = %lld\n", t1, a[t1], t2, a[t2]);
            ll x = (a[t1] - a[t2]) / (n + 1);
            a[t1] -= n * x;
            a[t2] += x;
            for (int i = 0; i < n; i++) {
                if (i != t1 && i != t2) a[i] += x;
            }
            t1 = max_id(), t2 = min_id();
            ans += x;
        }
        t2 = min_id();
        ll st = a[t2] - n;
        for (int i = 0; i < n; i++) {
            a[i] -= st;
        }
        ans += st * n;
        while (!check()) {
            int t = max_id();
            for (int i = 0; i < n; i++) {
                if (i != t) a[i]++;
                else a[i] -= n;
            }
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
