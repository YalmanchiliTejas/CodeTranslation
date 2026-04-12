#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    multiset <int> bst;
    int a;
    cin >> a;
    bst.insert(a);
    for (int i = 1; i < n; i++) {
        cin >> a;
        auto ptr = bst.lower_bound(a);
        if (ptr == bst.begin()) {
            bst.insert(a);
        } else {
            ptr--;
            bst.erase(ptr);
            bst.insert(a);
        }
    }
    cout << bst.size() << endl;
    return 0;
}
