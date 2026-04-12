#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
    #include "header.h"
#else
    #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
    return;
}
lli dp[3001][3001][2];
vi ar;
lli solve(int l, int r, int p) {
    if(r<l) return 0;
    if(dp[l][r][p] != -1) return dp[l][r][p];
    if(p==1) {
        return dp[l][r][p] = max(solve(l,r-1,!p) + ar[r], solve(l+1,r,!p) + ar[l]);
    }
    else return dp[l][r][p] = min(solve(l,r-1,!p) - ar[r], solve(l+1,r,!p) - ar[l]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    preprocess();
    int n; cin>>n;
    ar.resize(n);
    memset(dp,-1,sizeof dp);
    rep(i,0,n) cin>>ar[i];
    cout<<solve(0,n-1,1)<<endl;
}

