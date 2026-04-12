#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll inf = 1e9;
const ll mod = 1e9 + 7;

const int MAXN = 1e6 + 100;


int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int cur = 0;
    deque<int> q[2];
    for (int i = 0; i < n; ++i) {
        q[cur].push_back(a[i]);
        q[cur ^ 1].push_front(a[i]);
        cur ^= 1;
    }
    for (int i : q[cur])
        printf("%d ", i);

    return 0;
}
