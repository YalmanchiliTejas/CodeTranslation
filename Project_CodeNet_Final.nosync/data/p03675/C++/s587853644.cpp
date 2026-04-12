#include "bits/stdc++.h"
using namespace std;

int main() {
        int i, j;
        int n;
        cin >> n;
        deque<int> dq;
        for (int i = 0; i < n; i ++) {
                int a;
                cin >> a;
                if (n & 1) {
                        if (i & 1) dq.push_front(a);
                        else dq.push_back(a);
                } else {
                        if (i & 1) dq.push_back(a);
                        else dq.push_front(a);
                }
        }
        while (!dq.empty()) {
                int ans = dq.back();
                dq.pop_back();
                if (!dq.empty()) cout << ans << ' ';
                else cout << ans << endl;
        }
        return 0;
}

