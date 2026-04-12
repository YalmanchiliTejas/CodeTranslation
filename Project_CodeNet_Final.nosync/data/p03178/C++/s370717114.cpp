#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

string str;
int d;
ll dp[10001][101];

int main() {
    cin >> str >> d;
    ll sum = 0;
    rep(i,str.size()) {
        int num = str[i]-'0';
        rep(j,num) {
            dp[i+1][(sum+j)%d] = (dp[i+1][(sum+j)%d]+1)%MOD;
        }
        sum += num;
        rep(j,d+1) {
            rep(k,10) {
                dp[i+1][(j+k)%d] = (dp[i+1][(j+k)%d] + dp[i][j]) % MOD;
            }
        }
    }
    dp[str.size()][sum%d]++;
    cout << (dp[str.size()][0]+MOD-1)%MOD << endl;
}

