#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    bool rev = false;
    deque<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (rev) {
            a.push_front(x);
        } else {
            a.push_back(x);
        }
        rev ^= 1;
    }
    if (rev) {
        for (int i = n - 1; i >= 0; i--) {
            printf("%d ", a[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

