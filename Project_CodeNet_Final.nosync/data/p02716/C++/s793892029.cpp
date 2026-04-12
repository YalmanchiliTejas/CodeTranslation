#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

#define INF 1e15

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vll a(n);
    rep(i,n) cin>>a[i];
    vector<vll> dp(n+1,vll(3,-INF));
    dp[0][1] = 0;
    dp[1][1] = 0, dp[1][2] = a[0];
    FOR(i,2,n)rep(j,3){
        int k = i/2+j-1;
        int j1 = k-(i-1)/2+1;
        int j2 = k-(i-2)/2;
        if (i&1 || j<2) dp[i][j] = max(dp[i-1][j1], dp[i-2][j2]+a[i-1]);
    }
    cout<<dp[n][1]<<"\n";
    return 0;
}
