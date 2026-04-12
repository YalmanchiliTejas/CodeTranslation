#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }

int X[100001];
int bit[100001];
int n;
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    int N;
    cin >> N;
    n = N;
    vint A(N);
    rep(i, N) {
        cin >> A[i];
    }
    multiset<int> maxA;
    int min_maxA = INF;
    int ans = 0;
    rep(i, N) {
        auto it = maxA.lower_bound(A[i]);
        if (maxA.begin() == it) {
            maxA.insert(A[i]);
        }
        else {
            maxA.erase((--it));
            maxA.insert(A[i]);
        }

    }
    cout << maxA.size() << endl;
    return 0;
}