#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    
    vector<ll> X(N), Y;
    for (auto&& x : X) {
        cin >> x;
    }
    Y = X;
    sort(X.begin(), X.end());

    ll lc = X[N / 2 - 1];
    ll rc = X[N / 2];

    for (auto y : Y) {
        if (y <= lc ) {
            cout << rc << endl;
        } else if (y >= rc) {
            cout << lc << endl;
        }
    }

    return 0;
}

