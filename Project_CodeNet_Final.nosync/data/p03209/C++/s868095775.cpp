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
#define EPS 10e-8
#define MAX_N 100000
#define MAX_ABIT 42

using namespace std;
typedef pair<int, int> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

llong N, X;

llong C(llong n) { return pow(2, n + 2) + EPS - 3; }
llong P(llong n) { return pow(2, n + 1) + EPS - 1; }

llong solve(llong n, llong pos, llong res) {
    //cout << n << " " << pos << " " << res << endl;
    if(n == 0) {
        if(X > pos)
            return res + 1;
        else if(X < pos - 1)
            return res - 2;
        else if(X == pos - 1)
            return res - 1;
        else
            return res;
    }

    if(X > pos) {
        return solve(n - 1, pos + C(n - 1) + 2, res + P(n - 1) + 1);
    } else if(X < pos) {
        return solve(n - 1, pos - C(n - 1) - 2, res - P(n - 1) - 1);
    } else return res;
}

int main(int argc, char **argv) {
    cin >> N >> X;

    cout << solve(N - 1, C(N - 1) + 2, P(N - 1) + 1) << endl;
}