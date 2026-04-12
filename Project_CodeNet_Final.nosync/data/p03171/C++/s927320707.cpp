#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL n,a[3005],dp[3005][3005];
LL solve(int front,int back) {
    if (front>back) return 0;
    if (dp[front][back]!=-1) return dp[front][back];
    if ((n-back+front-1)%2==0) return dp[front][back]=max(solve(front+1,back)+a[front],solve(front,back-1)+a[back]);
    else return dp[front][back]=min(solve(front+1,back)-a[front],solve(front,back-1)-a[back]); 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset (dp,-1,sizeof(dp));
    cout << solve(1,n) << endl;
    return 0;
}
