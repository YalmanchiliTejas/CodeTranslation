
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define double long double
typedef pair<int, int> II;
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(a,x) memset(a, x, sizeof(a))
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define fixed jasklcjalcjl

#define TWO(X) (1LL<<(X))
#define CONTAIN(S,X) ((S) & TWO(X))

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }

const int MN = 200111;
const int INF = 1000111000111000111LL;
pair<int,int> a[MN];
set< pair<int,int> > all;
set<int> fixed;

int get(int xmin, int xmax) {
    int X = xmax - xmin;
    int ymin = INF;
    int ymax = -INF;

    if (!all.empty()) {
        ymin = min(ymin, all.begin()->first);
        ymax = max(ymax, all.rbegin()->first);
    }

    if (!fixed.empty()) {
        ymin = min(ymin, *fixed.begin());
        ymax = max(ymax, *fixed.rbegin());
    }
    return X * (ymax - ymin);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(9) << boolalpha;
    int n;
    while (cin >> n) {
        FOR(i,1,n) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        }
        sort(a+1, a+n+1);
        int xmin = a[1].first, xmax = a[n].first;
        all.clear();
        fixed.clear();

        FOR(i,1,n) all.insert(make_pair(a[i].second, a[i].first));

        int res = get(xmin, xmax);

        while (!all.empty()) {
            auto it = all.end(); --it;
            
            int x = it->first, y = it->second;
            all.erase(it);

            fixed.insert(y);
            xmin = min(xmin, x);
            xmax = max(xmax, x);

            res = min(res, get(xmin, xmax));
        }
        cout << res << endl;
    }
    return 0;
}
