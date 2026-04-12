# include "bits/stdc++.h"

using namespace std;

#define endl "\n"
typedef long long int ll;

inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
inline void setPrecision(int n){cout.precision(n);}

//DEBUG
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;

ll INF = 1e10;
int MOD = 1e9+7;

int n;
vector<int> a;
vector<ll> pre;

ll dp[3001][3001][2];

ll calcts(int l, int r, int chance){
    if(l > r) return 0;
    if(l == r) return (n%2==1) ? a[l] : 0;
    ll seg = pre[r+1] - pre[l];
    if(dp[l][r][chance] > 0) return dp[l][r][chance];
    if(chance == 0){
        ll cr = calcts(l,r-1,1) + a[r];
        ll cl = calcts(l+1,r,1) + a[l];
        ll jiroR = seg - cr;
        ll jiroL = seg - cl;
        dp[l][r][chance] = (cr - jiroR > cl - jiroL) ? cr : cl;
    }
    else{
        ll taroR = calcts(l,r-1,0);
        ll cr = seg - taroR;
        ll taroL = calcts(l+1,r,0);
        ll cl = seg - taroL;
        dp[l][r][chance] =  (taroR - cr > taroL - cl) ? taroL : taroR;
    }
    return dp[l][r][chance];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    cin>>n;
    a.resize(n);
    pre.resize(n+1);
    for(int i=0;i<n;++i){
        cin>>a[i];
        pre[i+1] = pre[i]+a[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ts = calcts(0,n-1,0);
    dbg(ts);
    cout<<(2*ts - pre[n]);
    return 0;
}
