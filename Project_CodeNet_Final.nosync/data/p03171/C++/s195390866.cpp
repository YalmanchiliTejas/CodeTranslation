#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vll A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    vll dprow(N+1, 0);
    vvll dp(N+1, dprow);
    for(int w=1;w<=N;w++) {
        for(int i=0;i<=N-w;i++) {
            dp[i][i+w] = max(A[i] - dp[i+1][i+w],
                             A[i+w-1] - dp[i][i+w-1]);
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}