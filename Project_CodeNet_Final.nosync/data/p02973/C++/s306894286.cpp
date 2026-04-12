#include <cstdio>
#include <set>

using namespace std;

int main() {
    int n, a, cnt = 1;
    multiset<int> s;
    scanf("%d%d", &n, &a);
    s.insert(a);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a);
        if (*s.begin() >= a) ++cnt;
        else s.erase(--s.lower_bound(a));
        s.insert(a);
    }
    printf("%d\n", cnt);
    return 0;
}
