#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DP[3][110][5];

int main(){
    string S;
    ll K;
    cin >> S >> K;
    ll N = S.length();

    REP(i,N+1){
        REP(j,3){
            REP(k,2){
                DP[k][i][j] = 0;
            }
        }
    }

    DP[0][0][0] = 1;
    REP(i,N){
        int n = S[i] - '0';
        for(int j = 0; j <= 3; j++){
            for(int k = 0; k < 10; k++){
                if(k < n){
                    if(k == 0){
                        DP[1][i+1][j] += DP[0][i][j];
                        DP[1][i+1][j] += DP[1][i][j];
                    }
                    else{
                        DP[1][i+1][j+1] += DP[0][i][j];
                        DP[1][i+1][j+1] += DP[1][i][j];
                    }
                }
                else if(k == n){
                    if(k == 0){
                        DP[0][i+1][j] += DP[0][i][j];
                        DP[1][i+1][j] += DP[1][i][j];
                    }
                    else{
                        DP[0][i+1][j+1] += DP[0][i][j];
                        DP[1][i+1][j+1] += DP[1][i][j];
                    }
                }
                else{
                    DP[1][i+1][j+1] += DP[1][i][j];
                }
            }
        }
    }

    ll ans = 0;
    REP(i,2){
        ans += DP[i][N][K];
    }

    cout << ans << endl;
    return 0;
}
