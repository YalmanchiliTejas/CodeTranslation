#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
/*----------------------------------------------------------------*/

// int MOD = 998244353;
int MOD = 1000000007;

int dp[101][4][3] = {};

/*----------------------------------------------------------------*/
signed main(){

    string n;
    int K;
    cin >> n >> K;

    dp[0][0][1] = 1;

    for(int i = 1;i <= n.size();i++){
        int N = n[i-1]-'0';
        
        dp[i][0][0] = dp[i-1][0][0];
        if(N != 0)dp[i][0][0] += dp[i-1][0][1];

        for(int j = 1;j <= K;j++){
            dp[i][j][0] = dp[i-1][j-1][0]*9 + dp[i-1][j][0];
            if(N != 0)dp[i][j][0] += dp[i-1][j-1][1]*max(N-1,0LL) + dp[i-1][j][1];
        }
        for(int j = 1;j <= K;j++){
            if(N == 0)dp[i][j][1] = dp[i-1][j][1];
            else dp[i][j][1] = dp[i-1][j-1][1];
        }
    }
    cout << dp[n.size()][K][0] + dp[n.size()][K][1] << endl; 


    
	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=c++14 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://ddcc2020-qual.contest.atcoder.jp/tasks/ddcc2020_qual_b
// rm -r -f test;oj dl https://abc154.contest.atcoder.jp/tasks/abc154_b