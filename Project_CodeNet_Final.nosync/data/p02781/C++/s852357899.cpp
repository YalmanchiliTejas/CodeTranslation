#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {
    string S; cin >> S;
    int K; cin >> K;

    ll dp[110][2][100];
    fill( ( long long * )dp, ( long long * )dp + sizeof( dp ) / sizeof( long long ), 0 );
    dp[0][0][0] = 1;
    int L = S.size();

    repp(i,0,L) {
        int D = S[i] - '0';
        repp(j,0,2) {
            repp(k, 0, 100) {
                reppe(d, 0, (j ? 9 : D)) {
                    if (d == 0) dp[i + 1][j || (d < D)][k] += dp[i][j][k]; 
                    else dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[L][0][K] + dp[L][1][K] << endl;
}

