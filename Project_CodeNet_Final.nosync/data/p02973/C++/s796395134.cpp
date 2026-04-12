#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    reverse(v.begin(), v.end());

    multiset<int> se;
    for (int i = 0; i < n; i++) {
        auto p = se.upper_bound(v[i]);
        if (p != se.end()) se.erase(p);

        se.insert(v[i]);
    }

    cout << se.size() << endl;
    return 0;
}