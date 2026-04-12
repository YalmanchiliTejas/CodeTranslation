#define _USE_MAT_DEFINES
#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <numeric>
#include <functional>
using namespace std;

#define INF 1e9
#define MOD 1000000007;//1e9+7

int ctoi(char c) { return c - '0'; }

void solve() {
    string N;
    int K;
    cin >> N >> K;
    int digit = N.size();

    /*------------------------------------------------------------------------------*/
    /*dp0[i][j]=上からi桁まで決めて,0でない桁がj個あり,Nより小さい事が確定している  */
    /*dp0[i][j]=上からi桁まで決めて,0でない桁がj個あり,Nより小さい事が確定していない*/
    /*------------------------------------------------------------------------------*/
    vector<vector<int>>dp0(digit + 1, vector<int>(digit + 1, 0));
    vector<vector<int>>dp1(digit + 1, vector<int>(digit + 1, 0));
    dp1[0][0] = 1;

    for (int i = 0; i < digit ; i++){
        int dmax = ctoi(N[i]);
        for (int j = 0; j <= i; j++) {
            if (dmax == 0) {
                dp0[i + 1][j + 1] += dp0[i][j] * 9;
                dp0[i + 1][j] += dp0[i][j];
                dp1[i + 1][j] += dp1[i][j];
            }
            else {
                dp0[i + 1][j] += dp0[i][j] + dp1[i][j];
                dp0[i + 1][j + 1] += dp0[i][j] * 9 + dp1[i][j] * (dmax - 1);
                dp1[i + 1][j + 1] += dp1[i][j];
            }
        }
    }
    cout << dp0[digit][K] + dp1[digit][K];

}

int main() {
    solve();
    return 0;
}