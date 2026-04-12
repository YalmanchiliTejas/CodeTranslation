#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

struct color_max {
    int color;
    int max_value;
    color_max(int color, int max_value) : color(color), max_value(max_value) {}
};

bool operator<(const color_max &a, const color_max &b)
{
    return a.max_value < b.max_value;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n-1) cin >> a[i];

    vector<int> dp(n);
    vector<int> color(n);

    multiset<int> color_set;
    set<color_max> color_value_set;
    int ans = 0;
    int color_max = 0;
    FOR(i, 0, n-1) {
        auto itr = color_set.upper_bound(-a[i]);  
        if(itr==color_set.end()) {
            color_set.insert(-a[i]);
            color_max++;
        } else {
            color_set.erase(itr);
            color_set.insert(-a[i]);
        }
    }

    cout << color_max << endl;

    return 0;
} 