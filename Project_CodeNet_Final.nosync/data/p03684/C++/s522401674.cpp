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
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

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

void union_init(int d[], int s) { for (int i=0; i < s; i++) d[i]=i; }
int union_query(int d[], int n) { int res=n; while (d[res]!=res) res=d[res]; int m; while (d[n]!=n) {m=d[n];d[n]=res;n=m;} return res; };
int union_merge(int d[], int x, int y) { x=union_query(d,x); y=union_query(d,y); if (x==y)return -1; d[x]=y; return 1; }

const int MAXN = 100005;
int par[MAXN];

int n;

vector<PII> xi, yi;

priority_queue<PIII> pq;

int main() {
    GI(n);

    int x, y;

    union_init(par, n);

    LL res = 0;

    FORN(i, n) {
        GI(x);
        GI(y);

        xi.PB(MP(x, i));
        yi.PB(MP(y, i));
    }

    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());

    FORN(i, n-1) {
        pq.push(MP(xi[i].FF - xi[i+1].FF, MP(xi[i].SS, xi[i+1].SS)));
    }
    FORN(i, n-1) {
        pq.push(MP(yi[i].FF - yi[i+1].FF, MP(yi[i].SS, yi[i+1].SS)));
    }

    while (pq.size() > 0) {
        auto t = pq.top(); pq.pop();

        int i = t.SS.FF;
        int j = t.SS.SS;

        if (union_query(par, i) == union_query(par, j)) {
            continue;
        }
        else {
            res -= t.FF;
            union_merge(par, i, j);
        }
    }

    cout << res << "\n";

    return 0;
}