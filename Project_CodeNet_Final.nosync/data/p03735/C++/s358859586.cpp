#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef long long ll;

const int len = 2e5+5, inf = 1e9+5;
int suf[2*len];
ii arr[len];
vector<ii> vec;

int main(){
    int n, mn = inf, mx = -inf, mnrig = inf, mxlef = -inf;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &arr[i].fi, &arr[i].se);
        if (arr[i].fi > arr[i].se)
            swap(arr[i].fi, arr[i].se);

        mn = min(mn, arr[i].fi);
        mx = max(mx, arr[i].se);

        mnrig = min(mnrig, arr[i].se);
        mxlef = max(mxlef, arr[i].fi);
    }

    if (n == 1){
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++){
        vec.pb(mp(arr[i].fi, i));
        vec.pb(mp(arr[i].se, -1));
    }

    sort(vec.begin(), vec.end());

    suf[2*n-1] = -inf;
    for (int i = 2*n-2; i >= 0; i--){
        suf[i] = suf[i+1];
        if (vec[i+1].se != -1)
            suf[i] = max(suf[i], vec[i+1].fi);
    }

    ll ans = (mxlef-mn)*1LL*(mx-mnrig);

    for (int i = 0, cur = -inf; i < 2*n; i++){
        ans = min(ans, (mx-mn)*1LL*(max(cur, suf[i])-vec[i].fi));

        //printf("i = %d, po = %d, tp = %d, cur = %d, suf = %d\n", i, vec[i].fi, vec[i].se, cur, suf[i]);

        if (vec[i].se == -1)
            break;
        else
            cur = max(cur, arr[vec[i].se].se);
    }

    printf("%lld\n", ans);
    return 0;
}
