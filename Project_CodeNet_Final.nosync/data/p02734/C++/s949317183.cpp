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
const ll MOD = 998244353;

ll DP[4000][8000][3];

int main(){
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    DP[0][0][0] = 1;
    REP(i,N){
        ll a = A[i];
        REP(j,S+1){
            REP(k,3)
                DP[i+1][j][k] += DP[i][j][k];

            DP[i+1][j][1] += DP[i][j][0];
            DP[i+1][j][2] += DP[i][j][1];

            if(a + j > S) continue;
            DP[i+1][j+a][1] += DP[i][j][0];
            DP[i+1][j+a][1] += DP[i][j][1];

            DP[i+1][j+a][2] += DP[i][j][0];
            DP[i+1][j+a][2] += DP[i][j][1];
        }

        REP(j,S+1){
            REP(k,3){
                DP[i+1][j][k] %= MOD;
            }
        }
    }

    ll ans = DP[N][S][2];

    cout << ans << endl;
    return 0;
}
