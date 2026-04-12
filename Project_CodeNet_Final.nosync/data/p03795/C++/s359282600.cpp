
/*
    Created by 10_months
    Tag:
    Link:
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const long long inf = 1e17;
const int INF = 1e9 + 7;
const int N = 1234567;
const int M = 123456;

int n;

int main() {
    #ifdef home
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif       
    while (scanf("%d", &n) == 1) {
        int ans = 800 * n - (n / 15) * 200;
        printf("%d\n", ans);
    }
    return 0;
}
