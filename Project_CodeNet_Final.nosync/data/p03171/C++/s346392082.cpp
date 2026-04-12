#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int n;
int a[3010];
ll dp[3010][3010];
int vis[3010][3010];

ll rec(int l, int r) {
    if(l > r) return 0;
    if(vis[l][r]) return dp[l][r];

    vis[l][r] = 1;
    ll rsl = 0;

    if((n - r + l) % 2 == 1) { // 先攻
        rsl = -INF;
        chmax(rsl, rec(l + 1, r) + a[l]);
        chmax(rsl, rec(l, r - 1) + a[r]);
    } else {
        rsl = INF;
        chmin(rsl, rec(l + 1, r) - a[l]);
        chmin(rsl, rec(l, r - 1) - a[r]);
    }
    return dp[l][r] = rsl;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cout << rec(0, n - 1) << endl;

}
