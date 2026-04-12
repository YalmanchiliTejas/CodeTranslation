#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    string N;
    cin >> N;
    int t = N.size();
    int K;
    cin >> K;
    vector<vector<lint>> dp0(t+1, vector<lint>(K+2));
    vector<vector<lint>> dp1(t+1, vector<lint>(K+2));
    dp0[0][1] = 1;
    REP(i, t) {
        int x = N[i] - '0';
        REP(j, K+1) {
            dp0[i+1][j+1] = dp0[i][j] * (x != 0) + dp0[i][j+1] * (x == 0);
            dp1[i+1][j+1] = dp0[i][j] * max(0, x-1) + dp1[i][j] * 9 + dp0[i][j+1] * (x != 0) + dp1[i][j+1];
        }
    }
 
    cout << (dp0[t][K+1] + dp1[t][K+1]) << endl;
}