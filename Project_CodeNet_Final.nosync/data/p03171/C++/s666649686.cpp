#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;


ll N;
vector<ll> A;
ll DP[3005][3005];
bool grid[3005][3005];

ll rec(int i, int j, int cnt){
    if(grid[i][j]) return DP[i][j];
    
    if(i == j-1) {
        if(cnt == 0) DP[i][j] = max(A[i], A[j]) - min(A[i], A[j]);
        else DP[i][j] = min(A[i], A[j]) - max(A[i], A[j]);
        grid[i][j] = true;
        return DP[i][j];
    }
    if(i < j && j-1 >= 0) rec(i, j-1, (cnt+1)%2);
    if(i < j && i+1 < N) rec(i+1, j, (cnt+1)%2);
    if(cnt == 0) DP[i][j] = max(DP[i][j-1]+A[j], DP[i+1][j]+A[i]);
    else DP[i][j] = min(DP[i][j-1]-A[j], DP[i+1][j]-A[i]);
    grid[i][j] = true;
    return DP[i][j];
}



int main() {
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    memset(DP, 0, sizeof(DP));
    memset(grid, false, sizeof(grid));
    cout << rec(0, N-1, 0) << endl;
}