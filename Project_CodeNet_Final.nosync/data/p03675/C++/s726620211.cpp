#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;
deque<int> que;
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        if (i & 1) {
            que.push_front(val);
        } else que.push_back(val);
    }
    if (n & 1) {
        for (deque<int> :: iterator it = que.begin(); it != que.end(); ++it) {
            cout << *it << " ";
        }
    } else {
        deque<int> :: iterator it = que.end();
        it--;
        while (true) {
            cout << *it << " ";
            if (it == que.begin()) break;
            it--;
        }
    }
}

int main() {
#ifdef local
    freopen("data.txt", "r", stdin);
//    freopen("data.txt", "w", stdout);
#endif
    work();
    return 0;
}
