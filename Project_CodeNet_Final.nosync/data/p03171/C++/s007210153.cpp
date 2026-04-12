#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 3005;
const int MOD = int(1e9)+7;
const int INF = int(2e9)+5;
const ll INF64 = 1e18;

ll a[N],presum[N],dp[N][N];

int main () {
    int n;cin>>n;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        presum[i] = presum[i-1] + a[i];
        dp[i][i] = a[i];
    }
    for (int l=1;l<=n-1;l++) {
        for (int i=1;i<n-l+1;i++) {
            int j = i + l;
            ll x = a[j] + presum[j-1] - presum[i-1] - dp[i][j-1];
            ll y = a[i] + presum[j] - presum[i] - dp[i+1][j];
            dp[i][j] = max(x,y);
        }
    }
    ll ans = dp[1][n];
    cout<<2*ans-presum[n]<<endl;
    return 0;
}