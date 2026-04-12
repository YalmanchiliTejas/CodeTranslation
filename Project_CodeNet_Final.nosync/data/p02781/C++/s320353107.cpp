#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;
//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n; //Nの各桁の数字を格納するベクター
long long dp[200][2][10];
int main(void)
{
    cin >> N;
    int K;
    cin >> K;

    //ベクターnを構成
    for (auto a : N)
    {
        n.push_back(a - '0');
    }
    int l = N.size(); //nの長さ
    dp[0][0][0] = 1;
    if (l == 1)
    {
        if (K >= 2)
        {
            cout << 0 << endl;
        }
        else if (K == 1)
        {
            cout << n[0] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }
    for (int i = 0; i < l; i++)
    {
        for (int smaller = 0; smaller < 2; smaller++)
        {
            for (int j = 0; j <= K; j++)
            {
                for (int x = 0; x <= (smaller ? 9 : n[i]); x++)
                {
                    if (x == 0)
                    {
                        dp[i + 1][smaller || x < n[i]][j] += dp[i][smaller][j];
                    }
                    else
                    {
                        if (j + 1 <= K)
                            dp[i + 1][smaller || x < n[i]][j + 1] += dp[i][smaller][j];
                    }

                    //dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][j];
                }
            }
        }
    }
    cout << dp[l][0][K] + dp[l][1][K] << endl;
}