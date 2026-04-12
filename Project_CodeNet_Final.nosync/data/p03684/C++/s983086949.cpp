#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
using namespace std;

#define eps 1e-8
#define mod 1000000007
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int n;
vector<int> x, y, p, q;

int root(int node) {
    return node == p[node] ? node : (p[node] = root(p[node]));
}

auto cmp = [](pair<int, pii> a, pair<int, pii> b){return a.first > b.first;};

priority_queue<pair<int, pii>, vector<pair<int, pii>>, decltype(cmp)> pq(cmp);

int main() {
    cin >> n;
    x.resize(n), y.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        p[i] = q[i] = i;
    }
    sort(all(q), [](int a, int b){return x[a] < x[b];});
    for (int i = 1; i < n; ++i) {
        pq.push({x[q[i]] - x[q[i - 1]], {q[i], q[i - 1]}});
    }
    sort(all(q), [](int a, int b){return y[a] < y[b];});
    for (int i = 1; i < n; ++i) {
        pq.push({y[q[i]] - y[q[i - 1]], {q[i], q[i - 1]}});
    }
    ll res = 0;
    int cnt = n;
    while (cnt > 1) {
        auto item = pq.top();
        pq.pop();
        int roota = root(item.second.first), rootb = root(item.second.second);
        if (roota == rootb) continue;
        res += item.first;
        --cnt;
        p[roota] = rootb;
    }
    cout << res;

    return 0;
}