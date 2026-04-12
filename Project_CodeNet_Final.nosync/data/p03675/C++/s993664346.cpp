#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> internal;
    int n;
    cin >> n;
    bool rev = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (rev)
            internal.push_front(x);
        else
            internal.push_back(x);
        rev = 1 - rev;
    }
    if (rev) {
        for (int i = 0; i < n; i++) {
            cout << internal.back() << " ";
            internal.pop_back();
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << internal.front() << " ";
            internal.pop_front();
        }
    }
}