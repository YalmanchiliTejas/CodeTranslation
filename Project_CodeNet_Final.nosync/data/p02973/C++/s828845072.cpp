#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    deque <int> bst;
    int a;
    cin >> a;
    bst.push_back(a);
    for (int i = 1; i < n; i++) {
        cin >> a;
        auto ptr = lower_bound(bst.begin(), bst.end(), a);
        if (ptr == bst.begin()) {
            bst.push_front(a);
        } else {
            int itr = ptr - bst.begin();
            bst[itr - 1] = a;
        }
    }
    cout << bst.size() << endl;
    return 0;
}
