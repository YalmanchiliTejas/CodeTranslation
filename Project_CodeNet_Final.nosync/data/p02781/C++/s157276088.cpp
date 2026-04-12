#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define len(x) (int)(x).size()
#define rep(i,x) for(int i=0;i<x;++i)

typedef long long ll;
typedef long double ld;

using namespace std;
#define int long long
const int N = 111;
int dp[N][4][2];
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string n;cin >> n;
    int k;cin >> k;
    ll answer = 0;
    for(int j = 1; j < len(n); ++j){
        if(j < k)continue;
        if(k == 1)answer += 1ll * 9;
        if(k == 2)answer += 1ll * 9 * (j - 1) * 9;
        if(k == 3)answer += 1ll * 9 * (j - 1) * (j - 2) / 2 * 9 * 9;
    }
    dp[1][1][0] = (n[0]-'0'-1);
    dp[1][1][1] = 1;
    for(int i = 2; i <= len(n); ++i){
        for(int j = 0 ; j < 4; ++j){
            dp[i][j][0] = dp[i-1][j][0] ;
            if(n[i-1]=='0')dp[i][j][1] = dp[i-1][j][1];
            else dp[i][j][0] += dp[i-1][j][1];
        }
        for(int done = 1; done < k; ++done){
            dp[i][done + 1][0] += 9 * dp[i-1][done][0];
            if(n[i-1]!='0')
            dp[i][done + 1][0] += (n[i-1]-'0'-1) * dp[i-1][done][1];
            if(n[i-1]!='0')
            dp[i][done + 1][1] += dp[i - 1][done][1];
        }
    }
//    cout << len(n) << ' ' << N << endl;
//    cerr << answer << endl;
//    cerr << dp[len(n)][k][1] << ' ' << dp[len(n)][k][0];
    answer += dp[len(n)][k][0] + dp[len(n)  ][k][1];
    cout << answer;
    return 0;
}
