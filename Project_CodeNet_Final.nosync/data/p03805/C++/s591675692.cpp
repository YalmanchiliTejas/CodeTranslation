#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m, a, b, ans = 0;
    scanf("%d%d", &n, &m);
    vector< vector<int> > e(n + 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        e.at(a).push_back(b);
        e.at(b).push_back(a);
    }
    queue< pair< set<int>, int > > q;
    q.push({{1}, 1});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (t.first.size() == n) {
            ++ans;
            continue;
        }
        for (auto i = e.at(t.second).begin(); i != e.at(t.second).end(); ++i) if (t.first.find(*i) == t.first.end()) {
                auto s = t;
                s.first.insert(*i);
                s.second = *i;
                q.push(s);
        }
    }
    printf("%d\n", ans);
    return 0;
}
