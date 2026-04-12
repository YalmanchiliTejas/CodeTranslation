#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const INF = 1LL<<60;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int n;
ll dp[3010][3010];
int a[3010];

ll rec(int l,int r) {
    if (dp[l][r] > -INF) return dp[l][r];
    if (l > r) dp[l][r] = 0;
    else if ((l+n-r)&1) dp[l][r] = max(rec(l+1,r)+a[l],rec(l,r-1)+a[r]);
    else dp[l][r] = min(rec(l+1,r)-a[l],rec(l,r-1)-a[r]);
    return dp[l][r];
}

int main() {
    cin >> n;
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n+1;++i) for (int j = 0;j < n+1;++j) dp[i][j] = -INF;
    cout << rec(0,n-1) << endl;
    return 0;
}