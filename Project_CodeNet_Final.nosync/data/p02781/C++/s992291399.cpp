#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

int dp[110][2][5]; //桁数、この桁までの数字がピッタリかより小さいか（桁DP恒例smallerの考え方）、0でない数字の個数
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string N;
    int K;
    cin >> N >> K;
    REP(i, 110)
    {
        REP(j, 2)
        {
            REP(k, 5)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 0;
    dp[0][1][0] = 1; //初期値

    REP(i, N.size())
    {
        int c = N[i] - '0';

        REP(j, 4)
        {
            dp[i + 1][0][j] += dp[i][0][j];         //smallerから0を追加->smaller
            dp[i + 1][0][j + 1] += dp[i][0][j] * 9; //smallerから1~9を追加->smaller
            if (c == 0)                             //c=0かどうかで、notsmallerからの挙動が若干異なる
            {
                dp[i + 1][1][j] += dp[i][1][j]; //notsmallerからc==0を追加->notsmaller
            }
            else
            {
                dp[i + 1][0][j] += dp[i][1][j];               //notsmallerから0を追加->smaller
                dp[i + 1][0][j + 1] += dp[i][1][j] * (c - 1); //notsmallerから1~cの数字を追加できる->smaller
                dp[i + 1][1][j + 1] += dp[i][1][j];           //notsmallerからc!=0を追加->notsmaller
            }
        }
        dp[i + 1][0][0] = 1; //この桁まで全部ゼロパターン
    }
    // REP(i, N.size() + 1)
    // {
    //     REP(j, 2)
    //     {
    //         REP(k, 4)
    //         {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;

    return 0;
}