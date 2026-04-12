#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int n;
int a[3005];
ll dp[3005][3005];

int main(){
    cin >> n;
    rep(i,n)cin >> a[i];
    for(int i=0;i<=n;i++)dp[i][i]=0;
    for(int w=1;w<=n;w++){
        for(int l = 0;l+w<=n;l++){
            int r=l+w;
            if(w%2==n%2)dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
            else dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
        }
    }
    //rep(i,n)rep(j,n)cout << dp[i][j] << endl;
    cout << dp[0][n] << endl;
}