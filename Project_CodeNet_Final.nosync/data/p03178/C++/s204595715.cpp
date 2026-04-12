#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
const int N = 2e4+5, inf = 1e9+7;
int n, k, i, d, l;
int A[N], dp[N][101][2];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, a, b, ans = 0;
    string s;
    cin>>s>>d;
    dp[0][0][0]=1;
    n = sz(s);
    rep(i, 0, n) rep(j, 0, d) rep(k, 0, 2){
        dp[i][j][k]%=inf;
        rep(l, 0, 10) {
            if(l>s[i]-'0' && !k) break;
            dp[i+1][(j+l)%d][k|(l<s[i]-'0')] += dp[i][j][k];
        }
    }
    cout<<(dp[n][0][0]+dp[n][0][1]-1+inf)%inf;
}