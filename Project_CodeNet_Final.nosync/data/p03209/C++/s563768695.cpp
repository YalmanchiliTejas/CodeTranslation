#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<ll> len(60, 1), p(60, 1);

ll solve(int n, ll x){
    if(n == 0) return 1;

    if(x == 1) return 0;
    else if(x <= 1 + len[n-1]) return solve(n - 1, x - 1);
    else if(x == 2 + len[n-1]) return p[n-1] + 1;
    else if(x <= 2 * (1 + len[n-1])) return p[n-1] + 1 + solve(n - 1, x - 2 - len[n-1]);
    else return p[n];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    ll x; cin>>x;
    for(int i=0; i<n; i++){
        len[i+1] = len[i] * 2 + 3;
        p[i+1] = p[i] * 2 + 1;
    }

    cout << solve(n, x) << endl;

    return 0;
}