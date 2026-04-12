/*input
10 3 4 2 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int N , A , B , C , D;
int c[MAX][MAX] , gi[MAX] , ni[MAX] , np[MAX][MAX] , dp[MAX][MAX];
void U(int &now , int val){ now = (now + val) % mod; }
int32_t main(){
    IOS;
    gi[0] = ni[0] = ni[1] = 1;
    REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 2 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;
    REP(i , 1 , MAX) REP(j , 1 , MAX){
        if(j == 1) np[i][j] = ni[i];
        else np[i][j] = np[i][j - 1] * ni[i] % mod;
    }
    REP(i , 0 , MAX) REP(j , 0 , i + 1){
        if(i == j) c[i][j] = 1;
        else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }

    cin >> N >> A >> B >> C >> D;
    dp[A][N] = 1;
    REP(i , A , B + 1){
        REP(j , 0 , N + 1){
            // DB4(i , j , dp[i][j] , "");
            U(dp[i + 1][j] , dp[i][j]);
            REP(k , C , D + 1){
                if(k * i > j) break;
                else {
                    int all = k * i;
                    int tmp = gi[all] * np[i][k] % mod * ni[k] % mod;
                    U(dp[i + 1][j - all] , dp[i][j] * c[j][all] % mod * tmp % mod);
                }
            }
        }
    }
    cout << dp[B + 1][0] << endl;
    return 0;
}