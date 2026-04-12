#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <set>
#include <deque>

using namespace std;

template<typename T>inline T get(){T x;cin>>x;return x;}

int main()
{
    int n = get<int>();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = get<int>();
    deque<int> b;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool f = false;

        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it == b.begin()) {
            b.push_front(a[i]);
        } else {
            it--;
            *it = a[i];
        }
    }
    cout << b.size() << endl;
    return 0;
}