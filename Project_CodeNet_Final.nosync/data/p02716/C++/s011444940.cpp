#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

/*
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>
*/

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    REP(i, 0, N){
        int p;
        cin >> p;
        A[i] = p;
    }
        
    int select = N/2;

    vector<vector<long>> DP(select, vector<long>(3, 0));
    REP(i, 0, 3) DP[0][i] = A[i];
    if(N % 2){
        REP(i, 1, select){
            DP[i][0] = DP[i-1][0] + A[i * 2];
            DP[i][1] = max(DP[i-1][0] + A[i * 2 + 1], DP[i-1][1] + A[i * 2 + 1]);
            long temp =  max(DP[i-1][0] + A[i * 2 + 2], DP[i-1][1] + A[i * 2 + 2]);
            DP[i][2] = max(temp, DP[i-1][2] + A[i * 2 + 2]);
        }
    }else{
        REP(i, 1, select){
            DP[i][0] = DP[i-1][0] + A[i * 2];
            DP[i][1] = max(DP[i-1][0] + A[i * 2 + 1], DP[i-1][1] + A[i * 2 + 1]);
        }
    }
    long ans = 0-__LONG_MAX__;
    REP(i, 0, 2+ N % 2)ans = max(ans, DP[select-1][i]);
    cout << ans << endl;
}