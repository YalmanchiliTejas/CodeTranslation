#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double LD;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define ln << endl
#else
#define debug false
#define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '


pair<long, long> XY[200000];

signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    int N;
    scanf("%d",&N);

    long xm = LLONG_MAX, xM = 0, ym = LLONG_MAX, yM = 0;
    times(N, i) {
        int X, Y;
        scanf("%d%d",&X,&Y);
        long x = min(X, Y), y = max(X, Y);
        XY[i] = {x, y};
        xm = min(x, xm);
        xM = max(x, xM);
        ym = min(y, ym);
        yM = max(y, yM);
    }
    sort(XY, XY + N);

    long k = LLONG_MAX, l = XY[N-1].first, yl = LLONG_MAX;
    times(N, i) {
        if(XY[i].first > yl) {
            k = min(k, l - yl);
            if(debug) cout << "*" << k ln;
            break;
        }
        yl = min(yl, XY[i].second);
        k = min(k, l - XY[i].first);
        l = max(l, XY[i].second);
        if(debug) cout << "*" << k sp << l ln;
    }

    cout << min((yM - ym) * (xM - xm), (yM - xm) * k) ln;

    return 0;
}
