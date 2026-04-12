#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i & 1)
            deq.push_back(a);
        else
            deq.push_front(a);
    }

    bool first = true;
    if ((n & 1) == 0) {
        reverse(deq.begin(), deq.end());
    }
    for (int x : deq) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << x;
    }
    cout << endl;
    return 0;
}
