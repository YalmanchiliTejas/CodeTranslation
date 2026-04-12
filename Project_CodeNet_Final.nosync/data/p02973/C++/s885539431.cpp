#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> deque;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(deque.begin(), deque.end(), a[i]) - deque.begin();
        if (p == 0) deque.push_front(a[i]);
        else deque[p - 1] = a[i];
    }
    int res = deque.size();

    cout << res << endl;
}
