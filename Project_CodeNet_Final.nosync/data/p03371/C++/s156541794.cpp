#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <chrono>
#include <random>
#include <stack>
#include <ctime>
#include <queue>
#include <list>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define FORR(i, m, n) for(int i = m; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define INF 999999999

using namespace std;

typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

void swap(int *X, int *Y){
    int t = *X; *X = *Y; *Y = t;
}

int main() {
    llong a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (2 * c < a + b) {
        vector<llong > Ans;
        if (x < y) {
            Ans.push_back(c * x * 2 + (y - x) * b);
        } else {
            Ans.push_back(c * y * 2 + (x - y) * a);
        }
        Ans.push_back(2 * c * max(x, y));

        sort(Ans.begin(), Ans.end());
        cout << Ans[0] << endl;
    } else {
        cout << a * x + b * y << endl;
    }

    return 0;
}