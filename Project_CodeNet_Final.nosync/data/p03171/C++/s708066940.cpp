#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 3010;
const LL INF = (LL)1000*1000*1000*1000*1000*1000;
int n,a[MAXN];
LL dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
        cin>>a[i];
        if(n%2==0) {
            dp[i][i] = -a[i];
        }else {
            dp[i][i] = a[i];
        }
    }
    for(int len = 2; len<=n; len++) {
        for(int i=1; i<=n;i++) {
            int j = i+len-1;
            if(j>n) {
                continue;
            }
            if((n-len)%2==1) {
                dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            } else {
                dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
            }
        }
    }
    cout<<dp[1][n];
}
