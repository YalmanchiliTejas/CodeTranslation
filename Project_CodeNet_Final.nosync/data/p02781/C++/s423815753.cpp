#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) (x)*(x)
#define CEIL(a,b) ((a)+(b)-1) /(b)

typedef long long ll;
const int INF = 1001001001;

void sort_second(vector<pair<ll, ll>> &A, int N); // A:array of pair, N:size of array
ll pow_n(ll a, int n); // a^n
ll nCr(int n, int r); // nCr;

int main() {
    string N;
    cin >> N;
    int K, L;
    cin >> K;
    L = N.length();
    
    // 初期化
    int dp[L+1][2][K+2];
    rep(i, L+1) {
        rep(j, 2) {
            rep(k, K+2) dp[i][j][k] = 0;
        }
    }
    dp[0][0][0] = 1;
    
    rep(i, L) {
        int D = N[i] - '0'; // (i+1)桁目の数字
        rep(j, 2) {
            rep(k, K+1) {
                rep(l, (j ? 10 : D + 1)) {
                    dp[i+1][j || (l < D)][k + ((l!=0) ? 1:0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[L][0][K] + dp[L][1][K] << endl;

    return 0;
}

void sort_second(vector<pair<ll, ll>> &A, int N) {
    rep(i, N) swap(A.at(i).first, A.at(i).second);
    sort(all(A));
    rep(i, N) swap(A.at(i).first, A.at(i).second);
}
ll pow_n(ll a, int n) {
    rep(i, n) a*=a;
    return a;
}
ll nCr(int n, int r) {
    ll ret = 1;
    rep(i, r) ret *= n-i;
    rep(i, r) ret /= (i+1);
    return ret;
}