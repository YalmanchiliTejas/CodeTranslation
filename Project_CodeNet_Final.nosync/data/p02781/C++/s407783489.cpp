#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;
ll dp[4][2][105];

int main(){
    string s; cin >> s;
    int k; cin >> k;
    rep(i,4) rep(j,2) rep(l,105) dp[i][j][l] = 0;
    dp[0][1][0] = 1;
    for(int i=0;i<s.length();i++){
        int d = (int)(s[i]-'0');
        if(d==0){
            rep(j,k+1){
                dp[j][1][i+1] += dp[j][1][i];
            }
            rep(j,k){
                dp[j+1][0][i+1] += 9*dp[j][0][i];
            }
            rep(j,k+1){
                dp[j][0][i+1] += dp[j][0][i];
            }
        }else{
            rep(j,k){
                dp[j+1][1][i+1] += dp[j][1][i];
            }
            rep(j,k){
                dp[j+1][0][i+1] += 9*dp[j][0][i];
                dp[j+1][0][i+1] += (d-1)*dp[j][1][i];
            }
            rep(j,k+1){
                dp[j][0][i+1] += dp[j][0][i];
                dp[j][0][i+1] += dp[j][1][i];
            }
        }
    }
    cout << dp[k][1][s.length()] + dp[k][0][s.length()] << endl;
    return 0;
}