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

int main() {
    double r1, r2;
    cin >> r1 >> r2;

    double ans = r1*r2/(r1+r2);

    printf("%.7f\n", ans);

    return 0;
}