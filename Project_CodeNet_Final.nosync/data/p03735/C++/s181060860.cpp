//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 200005
#define oo 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, x[maxN], y[maxN], cnt[maxN];
vector<ii> p;

int main () {
    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] < y[i]) swap(x[i], y[i]);
        p.pb(mp(x[i], i)); p.pb(mp(y[i], i));
    }

    if (n == 1) {
        puts("0");
        return 0;
    }

    sort(p.begin(), p.end());
    //fto(i, 0, sz(p)-1) printf("%d %d\n", p[i].ff, p[i].ss);

    ll ans = 1LL*oo*oo;
    if (p[0].ss != p[sz(p)-1].ss) {
        int r = 0, cntDiff = 0;
        fto(l, 1, sz(p)-2) {
            while (r < sz(p)-2 && cntDiff < n) {
                ++r;
                if (cnt[p[r].ss] == 0) ++cntDiff;
                ++cnt[p[r].ss];
            }
            if (cntDiff == n) ans = min(ans, 1LL*(p[sz(p)-1].ff-p[0].ff)*(p[r].ff-p[l].ff));
            --cnt[p[l].ss];
            if (cnt[p[l].ss] == 0) --cntDiff;
        }
    }

    int minX = oo, maxX = 0, minY = oo, maxY = 0;
    fto(i, 1, n) {
        minX = min(minX, x[i]);
        maxX = max(maxX, x[i]);
        minY = min(minY, y[i]);
        maxY = max(maxY, y[i]);
    }
    ans = min(ans, 1LL*(maxX-minX)*(maxY-minY));

    cout << ans;

    return 0;
}
