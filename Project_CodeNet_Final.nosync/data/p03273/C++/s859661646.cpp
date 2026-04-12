#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <set>
#include <map>
#include <deque>
#include <queue>
#define px first
#define py second
#define fi first
#define se second
#define LD long double

//#define DEBUG
#ifdef DEBUG
#include "Debug.h"
#endif // DEBUG

using namespace std;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<int> x(n, 1);
    vector<int> y(m, 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#'){
                x[i] = 0;
                y[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (y[j]) {
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
