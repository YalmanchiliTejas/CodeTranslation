#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 998244353;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}


int a[4000];
int dp[4000][4000];
signed main(){
    int ans = 0;
    int n,s;
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(j==a[i]){
                dp[i][j] = dp[i-1][j] + i;
            }
            else if(j-a[i] < 0){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j]+ dp[i-1][j-a[i]];

            }
            dp[i][j] %= MOD;
            ans += dp[i][s];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}