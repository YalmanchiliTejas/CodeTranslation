#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////

const ll LINF = 1001002003004005006ll;
int n;
int a[3010];
ll memo[3010][3010];
bool used[3010][3010];

ll rec(int s, int t) {
    if (s == t) return 0;
    if (used[s][t]) return memo[s][t];
    used[s][t] = true;
    ll ans = -LINF;
    chmax(ans, a[s] - rec(s+1, t));
    chmax(ans, a[t-1] - rec(s, t-1));
    return memo[s][t] = ans;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    cout << rec(0, n) << endl;
    return 0;
}
