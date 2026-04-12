#include <cstdio>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    vector< set<int> > e(n);
    vector< vector<int> > d(1 << n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        e.at(a).insert(b);
        e.at(b).insert(a);
    }
    d.at(1).at(0) = 1;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) {
            if ((i & (1 << k)) == 0 && e.at(j).find(k) != e.at(j).end()) d.at(i | (1 << k)).at(k) += d.at(i).at(j);
        }
    }
    printf("%d\n", accumulate(d.back().begin(), d.back().end(), 0));
    return 0;
}
