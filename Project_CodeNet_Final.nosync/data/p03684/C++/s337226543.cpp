#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
pair<pii, int> a[100100];
vector<pair<int, pii> > e;
int par[100100];

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return a.f < b.f;
}

bool cmp1(pair<pii, int> a, pair<pii, int> b) {
    pii x = mp(a.f.s, a.f.f);
    pii y = mp(b.f.s, b.f.f);
    return x < y;
}

int dist(pii a, pii b) {
    return min(abs(a.f - b.f), abs(a.s - b.s));
}

void add_edges() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j < i + 20; j++) {
            e.pb(mp(dist(a[i].f, a[j].f), mp(a[i].s, a[j].s)));
        }
    }
}

int get_parent(int v) {
    if (v == par[v]) return v;
    return par[v] = get_parent(par[v]);
}

void merge(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    if (x == y) return;
    if (rand()&1) par[x] = y;
    else par[y] = x;
}

int main(){

    srand(time(NULL));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].f.f, &a[i].f.s);
        a[i].s = i;
    }

    sort(a, a + n, cmp);
    add_edges();
    sort(a, a + n, cmp1);
    add_edges();

    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    sort(all(e));
    ll ans = 0;
    for (int i = 0; i < e.size(); i++) {
        int x = e[i].s.f, y = e[i].s.s;
        if (get_parent(x) != get_parent(y)) {
            ans += e[i].f;
            merge(x, y);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
