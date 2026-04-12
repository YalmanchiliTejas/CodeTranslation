#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n, l, r;
llong a[55];

bool is_u(llong x) {
    for (int i = 0; i < n; i++) {
        if (x % a[i] == 0) {
            return i % 2 == 0; 
        }
    }

    return n % 2 == 0;
}

int main() {
    cin >> n >> l >> r;

    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        llong cnt = 0;
        for (int i = l; i <= r; i++) {
            if (is_u(i)) cnt++;
        }

        cout << cnt << '\n';

        cin >> n >> l >> r;
    }
    

    return 0;
}

