#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int n;
lint x;
lint layer[55], dp[55];

void solve(int level, lint eat, lint &res){
    if(level == 0){
        res += (eat > 0);
        return;
    }
    eat = min(eat, layer[level]);
    lint tmp = layer[level] / 2LL;
    if(eat > tmp){
        res += dp[level - 1] + 1LL;
        solve(level - 1, eat - tmp - 1LL, res);
    }else{
        solve(level - 1, eat - 1LL, res);
    }
    return;
}

int main(){
    cin >> n >> x;
    layer[0] = 1;
    REP(i, 1, n + 1){
        layer[i] = layer[i - 1] * 2LL + 3LL;
    }
    dp[0] = 1;
    REP(i, 1, n + 1){
        dp[i] = dp[i - 1] * 2LL + 1LL;
    }
    lint ans = 0;
    solve(n, x, ans);
    cout << ans << endl;
    return 0;
}