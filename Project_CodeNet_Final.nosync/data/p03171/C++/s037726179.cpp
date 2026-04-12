#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define sz(x) (int)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 3e3+10;

int a[N];
ll dp[N][N][2];
int main(){
fast;
int n;
cin>>n;

fill(dp,0);

for(int i=0;i<n;i++) {
    cin>>a[i];
}
for(int i=0;i<n;i++) {
    dp[i][i][0]=a[i];
    dp[i][i][1]=-1*a[i];
}

for(int len=2;len<=n;len++) {
    for(int i=0;i<n-len+1;i++) {
        dp[i][i+len-1][0]=max(dp[i+1][i+len-1][1]+a[i], dp[i][i+len-2][1]+a[i+len-1]);
        dp[i][i+len-1][1]=min(dp[i+1][i+len-1][0]-a[i], dp[i][i+len-2][0]-a[i+len-1]);
    }
}

cout<<dp[0][n-1][0]<<endl;
return 0;
}