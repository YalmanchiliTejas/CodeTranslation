#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    // vector<string> S(N);
    vector<vector<int>> map(N, vector<int>(26));
    string str;
    int index;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            index = str[j] - 'a';
            map[i][index]++;
        }
    }

    // debug
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }

    string ans = "";
    int mn;
    for (int i = 0; i < 26; i++)
    {
        mn = INF;
        for (int j = 0; j < N; j++)
        {
            if (map[j][i] == 0)
            {
                break;
            }
            else
            {
                mn = min(mn, map[j][i]);
            }
            if (j == N - 1)
            {
                for (int k = 0; k < mn; k++)
                {
                    ans += 'a' + i;
                }
            }
        }
    }
    cout << ans << endl;
    return (0);
}