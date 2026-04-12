#include <bits/stdc++.h>
using namespace std;

int n, a[2*(int)1e5];
deque<int> b;

int main(void) {
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == (n-1) % 2) {
            b.push_front(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }
    for (auto itr = b.begin(); itr != b.end(); itr++) {
        if (itr == b.begin()) {
            cout << *itr; 
            continue;
        } else cout << " " << *itr;
    }
    cout << '\n';
    return 0;
}
