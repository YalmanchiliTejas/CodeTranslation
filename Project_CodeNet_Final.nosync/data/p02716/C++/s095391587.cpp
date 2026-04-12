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

#define INF 1e15

using namespace std;

vll a;
vll dp;
vll osum;

ll dfs(int k)
{
    if (k<1) return 0;
    if (dp[k]!=-INF) return dp[k];
    else dp[k] = dfs(k-2)+a[k];
    if (k&1) chmax(dp[k], osum[k]);
    else chmax(dp[k], dfs(k-1));
    return dp[k];
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    a.resize(n);
    dp.resize(n,-INF);
    osum.resize(n);
    rep(i,n) cin>>a[i];
    rep(i,n)if(i%2==0) osum[i]+=a[i];
    rep(i,n-1) osum[i+1]+=osum[i];
    cout<<dfs(n-1)<<"\n";
    return 0;
}
