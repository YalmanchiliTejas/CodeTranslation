#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> q;

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if ((n - i) & 1) q.push_back(x);
        else q.push_front(x);
    }
    while (!q.empty()) {
        printf("%d ", q.front()), q.pop_front();
    }
    return 0;
}