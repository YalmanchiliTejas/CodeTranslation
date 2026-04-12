#include <bits/stdc++.h>

using namespace std;

const int maxN = 3003;

#define int long long

long long DP[maxN][maxN];
int A[maxN];
int n;
const long long INF = 1e16;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            DP[i][j] = -INF;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n-k; i++){
            if(k == 0) DP[i][i+k] = A[i];
            //if(i >= n) break;
            else{
                DP[i][i+k] = max(DP[i+k][i+k] - DP[i][i+k-1], DP[i][i] - DP[i+1][i+k]);
            }

        }
    }
    cout << DP[0][n-1] << "\n";
}

#undef int

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    //multitest = true;
    if (multitest) {
        int t; cin >> t;
        while (t--)
            solve();
    }
    else
        solve();
}
