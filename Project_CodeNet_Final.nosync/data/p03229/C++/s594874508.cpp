#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define X first
#define Y second
#define mp make_pair
#define eb emplace_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
}

const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, a[MAX_N];

int main()
{
#ifdef ANONYM
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    Read(n);
    for(int i=0; i<n; i++) Read(a[i]);
    sort(a, a+n);
    if(n%2 == 0) {
        LL lsum = 0;
        for(int i=0; i<n/2-1; i++) lsum += 2*a[i];
        lsum += a[n/2-1];
        LL rsum = 0;
        for(int i=n/2+1; i<n; i++) rsum += 2*a[i];
        rsum += a[n/2];
        printf("%lld\n", rsum - lsum);
    } else {
        LL lsum1 = 0, rsum1 = 0;
        for(int i=0; i<n/2-1; i++) lsum1 += 2*a[i];
        lsum1 += a[n/2-1];
        for(int i=n/2+1; i<n; i++) rsum1 += 2*a[i];
        lsum1 += a[n/2];
        LL lsum2 = 0, rsum2 = 0;
        for(int i=0; i<n/2; i++) lsum2 += 2*a[i];
        rsum2 += a[n/2];
        for(int i=n/2+2; i<n; i++) rsum2 += 2*a[i];
        rsum2 += a[n/2+1];
        printf("%lld\n", max(rsum1 - lsum1, rsum2 - lsum2));
    }
    return 0;
}
