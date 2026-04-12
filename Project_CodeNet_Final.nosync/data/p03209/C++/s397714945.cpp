#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll a(int L) {  // レベルLバーガーの厚さ

    if(L == 0) {
        return 1;
    }

    return 2*a(L-1) + 3;
}

ll p(int L) {  // レベルLバーガーに含まれるパティの数

    if(L == 0) {
        return 1;
    }

    return 2*p(L-1) + 1;
}

ll f(int L, ll x) {  // レベルLバーガーの下からx層に含まれるパティの数

    if(L == 0) {
        return 1;
    }

    if(x == 1) {
        return 0;
    }
    else if(x <= a(L-1) + 1) {
        return f(L-1, x-1);
    }
    else if(x == a(L-1) + 2) {
        return p(L-1) + 1;
    }
    else if(x <= 2*a(L-1) + 2) {
        return  p(L-1) + 1 + f(L-1, x - a(L-1) - 2);
    }
    else if(x == a(L)) {
        return p(L);
    }
}

int main() {
    int n;
    ll X;
    cin >> n >> X;

    cout << f(n, X) << endl;
    return 0;
}