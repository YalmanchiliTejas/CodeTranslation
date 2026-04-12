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

ll A[200100];
ll DP[200100][10];

int main(){
    ll N;
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }

    REP(i,N){
        REP(j,5){
            DP[i][j] = -1e18;
        }
    }

    DP[0][0] = A[0];
    DP[1][1] = A[1];
    DP[2][2] = A[2];
    REP(i,N){
        //ll a = A[i];
        REP(j,3){
            chmax(DP[i+2][j], DP[i][j] + A[i+2]);
            chmax(DP[i+3][j+1], DP[i][j] + A[i+3]);
            chmax(DP[i+4][j+2], DP[i][j] + A[i+4]);
        }
    }

    //ll num = N - (2*(N/2) - 1);
    //ll ans = -1;
    //for(int k = 0; k <= num; k++)
    //    //chmax(ans, DP[N-1][k]);
    //    chmax(ans, DP[N-1-k][num-k]);

    ll ans = LLONG_MIN;
    ll num = 1 + N%2;
    for(int d = 0; d <= num; d++){
        int i = N-1-d;
        chmax(ans, DP[i][num-d]);
    }

    //REP(i,N){
    //    REP(j,3){
    //        if(DP[i][j] < 0)
    //            printf("x ");
    //        else
    //            printf("%lld ", DP[i][j]);
    //    }
    //    printf("\n");
    //}

    cout << ans << endl;
    return 0;
}
