#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, a, N) for(int i = a; i < N; i++)

int A, B, C, X, Y;

ll dfs(int x, int y, ll z){
    if (x >= X && y >= Y) return z;
    ll ret = 5000000000;

    if (x < X) {
        ret = min(ret, dfs(X, y, z + A * (X - x)));
        ret = min(ret, dfs(X, y + (X - x), z + C * (X - x) * 2));
    }

    if (y < Y) {
        ret = min(ret, dfs(x, Y, z + B * (Y - y)));
        ret = min(ret, dfs(x + (Y - y), Y, z + C * (Y - y) * 2));
    }

    return ret;
}

int main() {
    cin >> A >> B >> C >> X >> Y;
    cout << dfs(0, 0, 0) << endl;
}