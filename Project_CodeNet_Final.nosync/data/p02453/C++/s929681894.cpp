#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
    }
    return 0;
}
