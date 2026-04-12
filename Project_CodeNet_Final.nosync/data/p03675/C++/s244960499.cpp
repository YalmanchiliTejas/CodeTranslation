#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i ++)

int main() {
        int n;
        cin >> n;
        deque<int> dq;
        rep(i, n) {
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
                cout << dq.back();
                if (dq.size() != 1) cout << ' ';
                else cout << endl;
                dq.pop_back();
        }
        return 0;
}

