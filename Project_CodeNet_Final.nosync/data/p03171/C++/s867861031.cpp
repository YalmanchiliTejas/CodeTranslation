#include<bits/stdc++.h>
#define ll long long
#define F(type, i, a, b) for(type i = a; (a <= b)?i <= b:i >= b; (a <= b)?i ++: i --)
#define RF(type, i, a, b) for(type i = a; i >= b;i --)
#define sz(a) sizeof(a)
#define deb(a) cout<<" ["<<#a<<"->"<<a<<"] "
#define next_line cout<<'\n'
using namespace std;

typedef pair<ll ,ll > pii;
typedef pair<ll,ll> pll;
typedef pair<char,ll > pci;
typedef map<ll ,ll > mii;
typedef map<ll,ll> mll;
typedef map<char,ll > mci;
typedef unordered_map<ll ,ll > umii;
typedef unordered_map<ll,ll> umll;
typedef unordered_map<char,ll > umci;
typedef vector<ll>  vll;
typedef vector<vector<ll> > vvll;

ll  n, *arr, **dp;

ll  MaxDiff(ll  be, ll  en){
    //deb(be);deb(en);next_line;
    if(be == en)
        return arr[be];
    if(dp[be][en] != -1LL)
        return dp[be][en];
    dp[be][en] = max( arr[be] - MaxDiff(be + 1, en), 
                arr[en] - MaxDiff(be, en - 1));
    return dp[be][en];
}

void solve()
{
    cin>>n;
    arr = new ll [sz(ll ) * n];
    dp = new ll  *[sz(ll  *) * n];
    F(ll , i, 0, n - 1){
        cin>>arr[i];
        dp[i] = new ll [sz(ll ) * n];
    }
    //memset(dp, -1, sz(dp) * n * n);
    F(ll , i, 0, n - 1){
        F(ll , j, 0, n - 1){
            dp[i][j] = -1LL;
            //deb(dp[i][j]);
        }
    }
    cout<<MaxDiff(0, n - 1)<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#else
    //#endif
    solve();
}
