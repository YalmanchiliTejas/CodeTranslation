#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2e5 + 5;
typedef long long LL;

LL x[maxn], y[maxn];
int n;

pair<LL, LL> p[maxn];
LL suf[maxn];
int main(){
    cin >> n;
    LL Rmax = 0, Rmin = 1e9, Bmax = 0, Bmin = 1e9;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld", &x[i], &y[i]);
        if(x[i] > y[i])
            swap(x[i], y[i]);
        Rmax = max(Rmax, x[i]);
        Rmin = min(Rmin, x[i]);
        Bmax = max(Bmax, y[i]);
        Bmin = min(Bmin, y[i]);
        p[i].first = x[i];
        p[i].second = y[i];
    } 
    LL ans = 1LL * (Rmax - Rmin) * (Bmax - Bmin);
    sort(p + 1, p + 1 + n);
    LL ans1 = p[n].first - p[1].first;
    LL pre = p[1].second;
    LL pre1 = p[1].second;
    for(int i = 2;i <= n;i++){
        ans1 = min(ans1, max(p[n].first, pre) - min(pre1, p[i].first));
        pre = max(pre, p[i].second);
        pre1 = min(pre1, p[i].second);
    }
    ans = min(ans, ans1 * (max(Bmax, Rmax) - min(Rmin, Bmin)));
    cout << ans << endl;
    return 0;
}
