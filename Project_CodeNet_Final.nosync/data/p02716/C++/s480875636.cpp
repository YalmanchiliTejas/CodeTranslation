// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
#define pr pair<int,int>
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2e5 + 10;
int a[MAXN];
int dp[MAXN][2][3];
bool vis[MAXN][2][3];
int n;

int rec_even(int idx,int type,int cnt){
    if(idx > n) return 0;
    int &ans = dp[idx][type][cnt];

    if(vis[idx][type][cnt]) return ans;
    vis[idx][type][cnt] = 1;

    ans = -1e16;

    if(type == 0) {
        ans = max(ans,rec_even(idx+1,1,cnt));
        if(cnt == 0) ans = max(ans,rec_even(idx+1,0,cnt+1));
    }else {
        ans = max(ans,rec_even(idx+1,0,cnt) + a[idx]);
    }

    return ans;
}

int rec_odd(int idx,int type,int cnt){
    if(idx > n) return 0;
    int &ans = dp[idx][type][cnt];

    if(vis[idx][type][cnt]) return ans;
    vis[idx][type][cnt] = 1;

    ans = -1e16;

    if(type == 0) {
        ans = max(ans,rec_odd(idx+1,1,cnt));
        if(cnt < 2) ans = max(ans,rec_odd(idx+1,0,cnt+1));
    }else {
        ans = max(ans,rec_odd(idx+1,0,cnt) + a[idx]);
    }

    return ans;
}
void solve(){
    cin>>n;

    FOR(i,1,n) cin>>a[i];

    if(n%2 == 0){
        int ans = 0;
        for(int i=2;i<=n;i+=2) ans = ans + a[i];
        ZERO(vis);
        ans = max(ans,rec_even(1,1,0));
        cout<<ans<<endl;
    }else {
        int ans = 0;
        for(int i=3;i<=n;i+=2) ans = ans + a[i];
        ZERO(vis);
        ans = max(ans,rec_odd(1,1,0));
        ZERO(vis);
        ans = max(ans,rec_even(2,1,0));
        cout<<ans<<endl;
    }
}

signed main(){

   FastRead; 


    int t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}



