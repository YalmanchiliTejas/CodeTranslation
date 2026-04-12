#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);

    vector<int> a(n);

    multiset<int> s;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);

        if (s.empty()) {
            s.insert(a[i]);
        } else {
            auto it = s.lower_bound(a[i]);

            if (it == s.begin()) {
                s.insert(a[i]);
            } else {
                it--;
                s.erase(it);
                s.insert(a[i]);
            }
        }
    }

    printf("%d\n", s.size());

    return 0;
}