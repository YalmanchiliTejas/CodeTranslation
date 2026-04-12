#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

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
    queue< vector<int> > q;
    q.push({1});
    while (!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        if (t.size() == n) {
            ++ans;
            continue;
        }
        for (auto i = e.at(t.back()).begin(); i != e.at(t.back()).end(); ++i) if (find(t.begin(), t.end(), *i) == t.end()) {
                vector<int> s = t;
                s.push_back(*i);
                q.push(s);
        }
    }
    printf("%d\n", ans);
    return 0;
}
