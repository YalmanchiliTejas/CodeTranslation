#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int n;

const int MAXN = 200005;
int x[MAXN], y[MAXN], visited[MAXN];

set<PII> a, b;

LL getres() {
    LL adiff = a.rbegin()->FF - a.begin()->FF;
    LL bdiff = b.rbegin()->FF - b.begin()->FF;
    return adiff * bdiff;
}

int main() {
    GI(n);

    FOR1(i, n) {
        GI(x[i]);
        GI(y[i]);
        a.insert(MP(max(x[i], y[i]), i));
        b.insert(MP(min(x[i], y[i]), i));
    }

    memset(visited, 0, sizeof visited);

    LL res = getres();

    auto t = *a.rbegin();
    auto i = t.SS;

    while (!visited[i]) {
        a.erase(MP(max(x[i], y[i]), i));
        b.erase(MP(min(x[i], y[i]), i));

        a.insert(MP(min(x[i], y[i]), i));
        b.insert(MP(max(x[i], y[i]), i));

        res = min(res, getres());
        visited[i] = 1;

        t = *a.rbegin();
        i = t.SS;
    }

    cout << res << "\n";

    return 0;
}