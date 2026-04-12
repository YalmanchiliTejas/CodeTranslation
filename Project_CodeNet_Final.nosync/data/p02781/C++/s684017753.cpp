#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[110][5][2];

int main(){
    string N; cin >> N;
    int K; cin >> K;
    int n = N.size();
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4){
        if(N[i] == '0'){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+1][1] += 9*dp[i][j][1];
        }
        else{
            int k = N[i]-'0';
            dp[i+1][j][1] += dp[i][j][0]+dp[i][j][1];
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j+1][1] += 9*dp[i][j][1]+(k-1)*dp[i][j][0];
        }
    }
    //repr(i,1,n+1)rep(j,K+1){
      //cout << i << " " << j << " " << dp[i][j][0]+dp[i][j][1] << endl;
    //}
    cout << dp[n][K][0]+dp[n][K][1] << endl;
}
