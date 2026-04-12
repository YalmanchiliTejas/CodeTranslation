//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll length(ll L) {
    return 4 * ((ll)1 << L) - 3;
}

ll eat_all(ll L) {
    return ((ll)1 << (L+1)) - 1;
}

ll eat(ll L, ll X) {
    if (X <= 0) {
        return 0;
    }
    if (length(L) <= X) {
        return eat_all(L);
    }
    ll ans = 0;
    X--;
    ans += eat(L-1, X);
    X -= length(L-1);
    if (X <= 0) {
        return ans;
    }
    X--;
    ans += 1;
    ans += eat(L-1, X);
    return ans;
}

int main() {
    ll N, X;
    cin >> N >> X;
    cout << eat(N, X) << endl;
}

