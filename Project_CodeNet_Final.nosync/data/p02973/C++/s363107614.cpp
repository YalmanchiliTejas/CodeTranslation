#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        auto iter = s.lower_bound(a[i]);
        if (iter != s.begin()) {
            iter--;
            s.erase(iter);
        }
        s.insert(a[i]);
    }

    cout << s.size() << endl;

    return 0;
}