#define LOCAL

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>

using namespace std;

// From Errichto's Youtube stream
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
int N;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        return parent[x] = find(parent[x]);
    return x;
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (rand() & 1) {
        parent[px] = py;
    } else {
        parent[py] = px;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    vector<pair<int, int>> xs, ys;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        xs.emplace_back(x, i);
        ys.emplace_back(y, i);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    for (int i = 0; i + 1 < N; i++) {
        edges.push_back(make_pair(xs[i + 1].first - xs[i].first, make_pair(xs[i].second, xs[i+1].second)));
    }

    for (int i = 0; i + 1 < N; i++) {
        edges.push_back(make_pair(ys[i + 1].first - ys[i].first, make_pair(ys[i].second + N, ys[i+1].second + N)));
    }

    for (int i = 0; i < N; i++)
        edges.push_back(make_pair(0, make_pair(i, i + N)));

    sort(edges.begin(), edges.end());

    parent.resize(2*N);
    for (int i = 0; i < 2 * N; i++)
        parent[i] = i;

    int result = 0;

    for (auto e : edges) {
        int A = e.second.first;
        int B = e.second.second;
        int cost = e.first;

        if (find(A) != find(B)) {
            unite(A, B);
            result += cost;
        }
    }

    cout << result << "\n";

    return 0;
}
