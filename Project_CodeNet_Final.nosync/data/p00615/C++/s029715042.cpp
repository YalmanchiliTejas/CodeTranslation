#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000
typedef long long ll;

int n, m, t[30000];

int main(void) {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n+m; i++) {
            cin >> t[i];
        }
        sort(t, t+(n+m));
        int ma = t[0];
        for (int i = 1; i < n+m; i++) {
            ma = max(t[i]-t[i-1], ma);
        }
        cout << ma << endl;
    }
    return 0;
}