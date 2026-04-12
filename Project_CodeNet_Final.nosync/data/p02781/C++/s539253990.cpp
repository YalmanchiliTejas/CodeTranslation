#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

string S;
ll K;

ll dp[110][2][10];

int main(){
    cin >> S >> K;
    dp[0][0][0] = 1;
    rep(i,S.size()){
        ll n = S[i] - '0';
        rep(j,K+1){
            if(n != 0){
                dp[i+1][1][j+1] += 9 * dp[i][1][j] + (n-1) * dp[i][0][j];
                dp[i+1][1][j] += dp[i][1][j] + dp[i][0][j];
                dp[i+1][0][j+1] += dp[i][0][j];
            }else{
                dp[i+1][1][j+1] += 9 * dp[i][1][j];
                dp[i+1][1][j] += dp[i][1][j];
                dp[i+1][0][j] += dp[i][0][j];
            }
        }
    }
    cout << dp[S.size()][0][K] + dp[S.size()][1][K] << endl;
}
