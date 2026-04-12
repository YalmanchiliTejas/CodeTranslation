#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>
#include<bitset>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
pii XY[200200];

//2N個のボールのうち最大のものを赤、最小のものを青で塗った場合
int RMBm() {
    int RMax = -INF, Rmin = INF;
    int BMax = -INF, Bmin = INF;
    rep(i, N) {
        int r = max(XY[i].first, XY[i].second);
        int b = min(XY[i].first, XY[i].second);
        RMax = max(RMax, r);
        Rmin = min(Rmin, r);
        BMax = max(BMax, b);
        Bmin = min(Bmin, b);
    }
    return (RMax - Rmin) * (BMax - Bmin);
}

//2N個のボールのうち最大、最小のものを赤でぬる
pii blue[200200];

int RMrm1() {
    int maxv = -INF, minv = INF;
    rep(i, N) {
        int M = max(XY[i].first, XY[i].second);
        int m = min(XY[i].first, XY[i].second);
        blue[i] = pii(m, M);
        if (M > maxv) {
            maxv = M;
        }
        if (m < minv) {
            minv = m;
        }
    }
    sort(blue, blue + N);
    int bluemin = blue[0].first;
    int bluemax = blue[N - 1].first;
    blue[N].first = INF;
    int bluemin2 = INF;
    int res = (maxv - minv) * (bluemax - min(bluemin, bluemin2));
    rep(i, N) {
        bluemin2 = min(bluemin2, blue[i].second);
        bluemin = blue[i + 1].first;
        bluemax = max(bluemax, blue[i].second);
        res = min(res, (maxv - minv) * (bluemax - min(bluemin, bluemin2)));
    }
    return res;
}

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> XY[i].first >> XY[i].second;
    }
    cout << min(RMBm(), RMrm1()) << endl;
    return 0;
}
