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

    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (q.size() == 0) {
            q.push_back(a[i]);
        } else {
            if (a[i] <= q[0]) {
                q.push_front(a[i]);
            } else {
                int j = lower_bound(q.begin(), q.end(), a[i]) - q.begin();
                q[j-1] = a[i];
            }
        }
    }

    cout << q.size() << endl;

    return 0;
}