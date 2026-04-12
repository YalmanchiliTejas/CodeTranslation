#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
int n, x, rev;
deque<int> ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        if (rev) ans.push_front(x);
        else ans.push_back(x);
        rev ^= 1;
    }
    if (rev) reverse(ans.begin(), ans.end());
    for (auto &i : ans) printf("%d ", i);
}
