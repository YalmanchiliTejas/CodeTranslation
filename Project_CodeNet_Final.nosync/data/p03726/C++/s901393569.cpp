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

const int MAXN = 100005;
int deg[MAXN], leaves[MAXN];

int n;

vector< set<int> > adj;

queue<PII> q;

int nonleaf(int u) {
    for (auto& v : adj[u]) if (deg[v] > 1) return v;
    return -1;
}

int main() {
    GI(n);

    adj.resize(n+1);

    int a, b;

    memset(deg, 0, sizeof deg);

    FORN(i, n-1) {
        GI(a);
        GI(b);

        adj[a].insert(b);
        adj[b].insert(a);

        deg[a]++;
        deg[b]++;
    }

    memset(leaves, 0, sizeof leaves);

    FOR1(u, n) {
        for (auto& v : adj[u]) {
            if (deg[v] == 1) leaves[u] += 1;
        }

        if (leaves[u] > 1) {
            printf("First\n");
            return 0;
        }

        if (deg[u] == 2 && leaves[u] == 1) {
            q.push(MP(u, nonleaf(u)));
        }
    }

    while (n > 2) {
        auto t = q.front(); q.pop();

//        DEBUG(t.FF);
//        DEBUG(t.SS);

        // cut t.FF - t.SS

        adj[t.SS].erase(t.FF);
        deg[t.SS]--;

        if (deg[t.SS] == 1) {  // t.SS becomes a leaf
            int p = nonleaf(t.SS);
            leaves[p]++;

            if (leaves[p] > 1) {
                printf("First\n");
                return 0;
            }

            if (deg[p] == 2) {
                q.push(MP(p, nonleaf(p)));
            }
        }
        else {
            if (leaves[t.SS] > 1) {
                printf("First\n");
                return 0;
            }

            if (deg[t.SS] == 2 && leaves[t.SS] == 1) {
                q.push(MP(t.SS, nonleaf(t.SS)));
            }
        }

        n -= 2;
    }

    if (n == 2) {
        printf("Second\n");
    }
    else {
        printf("First\n");
    }

    return 0;
}