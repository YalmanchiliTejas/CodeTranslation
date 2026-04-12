#include <iostream>
 
using namespace std;
 
const int MAXN = 3010;
int N;
int score[MAXN];

int64_t dp[MAXN][MAXN][2];
bool isCalc[MAXN][MAXN][2];

int64_t solve(int leftPointer, int righPointer, int turn) {
    if (leftPointer > righPointer) return 0;

    int64_t ans = dp[leftPointer][righPointer][turn];
    bool isCalculated = isCalc[leftPointer][righPointer][turn];

    if (isCalculated) return ans;
    if (turn == 0) {
        if (leftPointer == righPointer) {
            ans = (-score[leftPointer] + solve(leftPointer + 1, righPointer, 1));
        } else {
            int64_t pickLeft = -score[leftPointer] + solve(leftPointer + 1, righPointer, 1);
            int64_t pickRight = -score[righPointer] + solve(leftPointer, righPointer - 1, 1);
            ans = min(pickLeft, pickRight);
        }
    } else {
        if ( leftPointer == righPointer ){
            ans = score[leftPointer] + solve(leftPointer + 1, righPointer, 0);
        } else {
            int64_t pickLeft = score[leftPointer] + solve(leftPointer + 1, righPointer, 0);
            int64_t pickRight = score[righPointer] + solve(leftPointer, righPointer - 1, 0);
            ans = max(pickLeft, pickRight);
        }
    }
    dp[leftPointer][righPointer][turn] = ans;
    isCalc[leftPointer][righPointer][turn] = true;

    return ans;
}

int main(){
    
 
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> score[i];

    cout << solve(1, N, 1);

    return 0;
}