#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

ll dp[3005][3005][2];
bool flg[3005][3005][2];

ll f(int i, int j, bool k, vector<int> &A) {
    if (flg[i][j][k]) return dp[i][j][k];
    if (i == j) {
        if (k) {
            flg[i][j][k] = 1;
            return dp[i][j][k] = -A[i];
        } else {
            flg[i][j][k] = 1;
            return dp[i][j][k] = A[i];
        }
    }
    ll res = 0;
    if (k) {
        res = min(f(i+1, j, 0, A) - A[i], f(i, j-1, 0, A) - A[j]);
    } else {
        res = max(f(i+1, j, 1, A) + A[i], f(i, j-1, 1, A) + A[j]);
    }
    flg[i][j][k] = 1;
    return dp[i][j][k] = res;
}

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) cin >> i;

    cout << f(0, N-1, 0, A) << endl;
}