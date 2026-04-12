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

int N;
ll a[3010];

ll dp[3010][3010];

ll rec(int i, int j) {
    if(dp[i][j] > 0) return dp[i][j];
    ll rsl = -1;
    if((N - (j - i)) % 2 == 0) { // 先攻
        if(j - i == 1) return a[i];
        rsl = max(rec(i + 1, j) + a[i], rec(i, j - 1) + a[j - 1]);
    } else {
        if(j - i == 1) return 0;
        rsl = INF;
        rsl = min(rec(i + 1, j), rec(i, j - 1));
    }
    return dp[i][j] = rsl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    cin >> N;
    ll sum = 0;
    rep(i, 0, N) {
        cin >> a[i];
        sum += a[i];
    }

    memset(dp, -1, sizeof(dp));
    ll x = rec(0, N);
    ll y = sum - x;
    cout << x - y << endl;
}
