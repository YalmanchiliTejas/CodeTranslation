
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>
#include <atcoder/all>

#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define MAXMIN(a,b,c) std::max(a,min(b,c))
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using namespace atcoder;


int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(a[i]));
    }

    segtree<int, op, e> seg(a);

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, v;
            scanf("%d %d", &x, &v);
            x--;
            seg.set(x, v);
        }
        else if (t == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            printf("%d\n", seg.prod(l, r));
        }
        else if (t == 3) {
            int p;
            scanf("%d %d", &p, &target);
            p--;
            printf("%d\n", seg.max_right<f>(p) + 1);
        }
    }
}