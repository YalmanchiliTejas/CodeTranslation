#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define int long long 
#define ld long double
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i>=0;i--)
#define loop(i,l,r) for(int i=l;i<r;i++)
#define rloop(i,r,l) for(int i=r;i>=l;i--)
#define watch(x) cerr<<(#x)<<"= "<<(x)<<endl;
#define watcharr(a) cerr<<(#a)<<"("<<sz(a)<<")= ";rep(i,sz(a))cerr<<a[i]<<",";cerr<<'\n';
#define inf 2000000000000000000LL
#define mod 1000000007
#define mod1 998244353
#define FASTIO std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

int n,k;
int a[3005];
int dp[3005][3005];

signed main() {
    FASTIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("stderr.txt", "w", stderr);
    // #endif

    // int tt=1;
    // cin>>tt;
    // while(tt--){
        cin>>n;
        int t;
        rep(i,n) cin>>a[i];
        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
                if(l==r) dp[l][r]=a[l];
                else dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
        // rep(i,n){ rep(j,n) cerr<<dp[i][j]<<' '; cerr<<endl;}
        cout<<dp[0][n-1]<<endl;

          
        
    // }
    cerr<<"Time Elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" sec";
    return 0;   
}