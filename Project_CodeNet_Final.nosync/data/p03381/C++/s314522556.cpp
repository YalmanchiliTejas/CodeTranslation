#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <tuple>
#include <list>
#include <deque>
#include <stack>
#include <complex>
#include <functional>
#include <regex>
#include <map>

using namespace std;

#define REP(i,a,b) for(int i=(a); i<(b); ++(i))
#define rep(i,n) REP(i,0,n)

const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const int PI = acos(-1);
const int INF = numeric_limits<int>::infinity() / 2;
const ll INFLL = numeric_limits<ll>::infinity() / 2;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int, int>> X(N);
    map<int, int> m;
    rep(i, N) {
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(X.begin(), X.end());
    rep(i, N) m[X[i].second] = i;
    rep(i, N) {
        int dst = m[i];
        if (dst < N / 2) cout << X[N/2].first << endl;
        else cout << X[N/2-1].first << endl;
    }
    return 0;
}
