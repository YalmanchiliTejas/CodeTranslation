#include<bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
#define repn(i, st, en) for(int i=st; i>=en; i--)
#define sq(a) (a*a)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll mod = 1e9+7;

const int nax = 3005;
ll a[nax];
vector<vector<ll>> dp;

ll recurse(int st, int en){
    if(st > en) return 0ll;
    if(~dp[st][en]) return dp[st][en];

    ll &z = dp[st][en];
    ll lt = recurse(st + 1, en);
    ll rt = recurse(st, en - 1);
    return z = max(a[st] - lt, a[en] - rt);
}


void solve(){
    int n;
    cin>>n;
    dp.resize(n, vector<ll>(n, -1));
    fr(i, n) cin>>a[i];
    cout<<recurse(0, n-1);   /// bool turn = 1, 0 for second player
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

