#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using namespace std;

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> p(n); repeat (i, n) scanf("%d", &p[i]);
    // solve
    vector<int> history;
    auto operate = [&](int k) {
        repeat_from (i, k, n) {
            swap(p[i], p[i - k]);
        }
        history.push_back(k);
    };
    while (p[0] != 0 or not is_sorted(whole(p))) {
        if (p[0] < p[n - 1] and p[0] != 0) {
            operate(n - 1);
        } else {
            operate(1);
        }
    }
    // output
    assert (is_sorted(whole(p)));
    assert (history.size() <= 100000);
    printf("%d\n", int(history.size()));
    for (int result_i : history) {
        printf("%d\n", result_i);
    }
    return 0;
}
