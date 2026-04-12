#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> m;
    m.reserve(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        auto it = upper_bound(m.begin(), m.end(), a, greater<>());
        if (it == m.end()) m.push_back(a); else *it = a;
    }

    cout << m.size() << endl;

    return 0;
}