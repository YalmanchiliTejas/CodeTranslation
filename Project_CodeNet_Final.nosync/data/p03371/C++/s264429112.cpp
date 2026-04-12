#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)

using namespace std;
typedef pair<int, int> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

int main(int argc, char **argv) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = A * X + B * Y;
    res = min(res, 2 * max(X, Y) * C);
    if(X > Y)
        res = min(res, 2 * Y * C + (X - Y) * A);
    else
        res = min(res, 2 * X * C + (Y - X) * B);
    
    cout << res << endl;
}