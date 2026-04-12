#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    string S;
    cin >> S;
    ll K;
    cin >> K;

    ll N = SZ(S);
    ll M = MAX(K,N);
    ll dp[N+1][2][M+1]; // dp[桁][未満フラグ][0でない個数]
    REP(i,0,N+1) {
        REP(smaller,0,2) {
            REP(k,0,M+1) {
                dp[i][smaller][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    REP(i,0,N) {
        REP(smaller,0,2) {
            REP(k,0,K+1) {
                REP(n,0,smaller?10:(S[i]-'0')+1) {
                    dp[i + 1][smaller || n < (S[i]-'0')][k + (n > 0)] += dp[i][smaller][k];
                }
            }
        }
    }

    PR(dp[N][0][K]+dp[N][1][K]);

    return 0;
}

/*



*/