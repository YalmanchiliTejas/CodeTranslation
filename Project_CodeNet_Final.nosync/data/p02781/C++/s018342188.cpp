#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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

/* Some Libraries */

ll dp[101][101][2];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int sz = s.size();
    int k; cin>>k;
    dp[0][0][0] = 1;
    rep(i,sz)rep(j,sz+1){
        if (s[i]=='0'){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+1][1] += 9*dp[i][j][1];
        }else{
            int c = s[i]-'0';
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][0];
            dp[i+1][j+1][1] += (c-1)*dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+1][1] += 9*dp[i][j][1];
        }
    }

    cout<<dp[sz][k][0]+dp[sz][k][1]<<endl;
    return 0;
}
