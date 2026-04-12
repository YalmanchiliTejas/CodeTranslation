#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

//桁dp 
// Nからの 1のくらいに下がっていく?

//dp[n][100]: n桁目で、0が100個

int main()
{
    string s;
    cin >> s;
    int K;
    cin >> K;

    
    //long long dp[ 102 ][ 2 ][ 2 ][102];
    long long dp[ 102 ][ 2 ][102];
    fill( ( long long * )dp, ( long long * )dp + sizeof( dp ) / sizeof( long long ), 0 );
    //dp[桁][smaller][leading_zero][0でない数]
    //leading_zero 0以外を入れたときに trueになる?
    //0でない数字だった

    dp[0][0][0] = 1;

    for(int i = 0; i < s.size(); ++i)
    {
        int D = s[i] - '0';

        for(int j = 0; j < 2; ++j)
        {
            for(int k = 0; k <= i; ++k)
            {
                //未満フラグ
                for(int d = 0; d <= (j ? 9 : D); ++d)
                {
                    if(d == 0)
                    {
                        dp[i+1][j || (d < D)][k] += dp[i][j][k];
                    }
                    else
                    {
                        dp[i+1][j || (d < D)][k+1] += dp[i][j][k];
                    }
                }
            }
        }
    }

    int N = s.size();

    ll res = dp[N][0][K] + dp[N][1][K];
    cout << res << endl;

    return 0;
}