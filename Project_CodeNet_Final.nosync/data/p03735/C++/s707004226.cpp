#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long int; using f64 = double; using str = string;
template <typename T> using vec = vector<T>;
template <typename T> using heap = priority_queue<T, vec<T>, greater<T>>;
#define times(n, i) for (i32 i = 0; i < (n); ++i)
#define range(a, b, i) for (i32 i = (a); i < (b); ++i)
#define upto(a, b, i) for (i32 i = (a); i <= (b); ++i)
#define downto(a, b, i) for (i32 i = (a); i >= (b); --i)
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define uniqueall(xs) (xs).erase(unique(all(xs)), (xs).end())
#define even(x) (((x) & 1) == 0)
#define odd(x) (((x) & 1) == 1)
#define head(xs) *(xs).begin()
#define last(xs) *(xs).rbegin()
#define append emplace_back
#define findge lower_bound
#define findgt upper_bound
const i64 MOD = 1000000007;
const f64 EPS = 1e-10;

i32 n;
i64 x[200000], y[200000];
vec<pair<i64, i32>> p;

i32 main()
{
    cin >> n;
    times(n, i) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
        p.append(make_pair(x[i], i));
        p.append(make_pair(y[i], i));
    }
    sortall(p);
    i64 xmin = INT_MAX, xmax = 0;
    i64 ymin = INT_MAX, ymax = 0;
    times(n, i) {
        xmin = min(xmin, x[i]);
        xmax = max(xmax, x[i]);
        ymin = min(ymin, y[i]);
        ymax = max(ymax, y[i]);
    }
    i64 ans = (xmax-xmin)*(ymax-ymin);
    i32 l = p.size() - 1;
    if (p[0].second != p[l].second) {
        i64 a = p[p.size() - 1].first - p[0].first;
        set<pair<i64, i32>> bs;
        bs.insert(make_pair(p[0].first == x[p[0].second] ? y[p[0].second] : x[p[0].second], p[0].second));
        bs.insert(make_pair(p[l].first == x[p[l].second] ? y[p[l].second] : x[p[l].second], p[l].second));
        times(n, i) {
            if (i != p[0].second && i != p[l].second) {
                bs.insert(make_pair(x[i], i));
            }
        }
        i64 b = bs.rbegin()->first - bs.begin()->first;
        times(n, i) {
            if (bs.begin()->second == p[0].second || bs.begin()->second == p[l].second) break;
            if (y[bs.begin()->second] == bs.begin()->first) break;
            i64 v = bs.begin()->first;
            i32 j = bs.begin()->second;
            bs.erase(bs.begin());
            bs.insert(make_pair(y[j], j));
            b = min(b, bs.rbegin()->first - bs.begin()->first);
        }
        ans = min(ans, a*b);
    }
    cout << ans << endl;
    return 0;
}