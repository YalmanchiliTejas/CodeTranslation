#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int c; cin >> c; c *= -1;
        auto it = ms.upper_bound(c);
        if (it == ms.end()) ms.insert(c);
        else {
            ms.erase(it);
            ms.insert(c);
        }
    }
    cout << ms.size() << endl;
    return 0;
}