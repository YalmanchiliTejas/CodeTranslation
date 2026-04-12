#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

int n;
struct Point{
    int x, y, id;
};
struct Edge{
    int v, u, w;
};
int root[500000];
int sz[500000];

int Root(int x)
{
    return x == root[x] ? x : (root[x] = Root(root[x]));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<Point> a(n);
    vector<Edge> e(2 * n - 2);
    for (int i = 0; i < n; i++) root[i] = i;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(all(a), [&](Point a, Point b){
         return a.x < b.x;
         });
    for (int i = 0; i + 1 < n; i++)
    {
        e[i] = {a[i].id, a[i + 1].id, a[i + 1].x - a[i].x};
    }
    sort(all(a), [&](Point a, Point b){
         return a.y < b.y;
         });
    for (int i = 0; i + 1 < n; i++)
    {
        e[i + n - 1] = {a[i].id, a[i + 1].id, a[i + 1].y - a[i].y};
    }
    sort(all(e), [&](Edge a, Edge b){
         return a.w < b.w;
         });
    ll ans = 0;
    for (int i = 0; i < 2 * n - 2; i++)
    {
        int a = Root(e[i].v);
        int b = Root(e[i].u);
        if (a == b)
        {
            continue;
        }
        if (sz[a] == sz[b])
            sz[a]++;
        if (sz[a] < sz[b])
        {
            root[a] = b;
        }
        else
        {
            root[b] = a;
        }
        ans += e[i].w;
    }
    cout << ans;
}
