#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 100;
const int MAX = 1e9 + 1;
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n;
ll a[60];
int id;

bool g() {
    id = 0;
    ll v = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > v) {
            id = i;
            v = a[i];
        }
    }
    return v >= n;
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    while (g()) {
        ll t = a[id] / (ll)n;
        for (i = 0; i < n; ++i) {
            if (i == id)
                a[i] %= (ll)n;
            else
                a[i] += t;
        }
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
