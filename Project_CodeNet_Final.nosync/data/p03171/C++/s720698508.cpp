#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
typedef long long ll;
const ll INF = 1LL << 60;

ll dp[3030][3030];
int N;
ll a[3030];
bool ischecked[3030][3030];
// First maximize |X-Y|
// Second minimize |X-Y|
ll rec(int l, int r,int t){
    if(l > r) return 0;
    if(ischecked[l][r]) return dp[l][r];
    ischecked[l][r] = true;
    ll ret;
    if(t%2==0){
        ret = -INF;
        ret = max(ret,rec(l+1,r,t^1) + a[l]);
        ret = max(ret,rec(l,r-1,t^1) + a[r]);
    } else {
        ret = INF;
        ret = min(ret,rec(l+1,r,t^1) - a[l]);
        ret = min(ret,rec(l,r-1,t^1) - a[r]);
    }
    return dp[l][r] = ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    REP(i,N) cin >> a[i];
    ll ans = rec(0,N-1,0);
    cout << ans << endl;
    return 0;
}