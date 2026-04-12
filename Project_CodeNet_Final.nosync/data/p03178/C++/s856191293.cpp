#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DPX[10010][110];
ll DPY[10010][110];

int main(){
    string K;
    cin >> K;
    int D;
    cin >> D;
    int N = K.size();

    DPX[0][0] = 1;
    REP(i,N){
        int d = K[i] - '0';

        REP(j,D){
            DPX[i+1][(j+d)%D] += DPX[i][j];
            DPX[i+1][(j+d)%D] %= MOD;

            REP(k,10){
                DPY[i+1][(j+k)%D] += DPY[i][j];
                DPY[i+1][(j+k)%D] %= MOD;
            }

            REP(k,d){
                DPY[i+1][(j+k)%D] += DPX[i][j];
                DPY[i+1][(j+k)%D] %= MOD;
            }
        }
    }

    ll ans = 0;
    ans += DPX[N][0];
    ans %= MOD;
    ans += DPY[N][0];
    ans %= MOD;
    ans -= 1;
    ans += MOD;
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
