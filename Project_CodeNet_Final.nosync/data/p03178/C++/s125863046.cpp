/** https://atcoder.jp/contests/dp/tasks/dp_s */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string K;
vector<int> k;
int d;
int f[10003][103][3];
const int MOD = 1e9 + 7;

int main()
{
    cin >> K >> d;

    for(int i = 0; i<(int)K.size(); i++)
        k.push_back(K[i] - '0');

    for(int i = 0; i< 10001; i++)
    for(int j = 0; j< 101; j++)
    for(int k = 0; k< 3; k++) f[i][j][k] = 0;

    for(int x = 1; x< 10; x++)
    {
        int st = (x < k[0] ? 0 : (x == k[0] ? 1 : 2 ));
        f[1][x%d][st]++;
    }

    for(int i = 1; i< k.size(); i++)
    for(int r = 0; r < d; r++)
    for(int st = 0; st < 3; st++)
    {
        if (f[i][r][st] == 0) continue;
        for(int x = 0; x < 10; x++)
        {
            int newst = st;
            if (st == 1)
                newst = (x < k[i] ? 0 : (x == k[i] ? 1 : 2 ));
            int newr = (r + x)%d;
            (f[i+1][newr][newst] += f[i][r][st])%= MOD;
        }
    }
    long long ans = 0;
    for(int i = 0; i< K.size(); i++) (ans+= f[i][0][0]+f[i][0][1]+f[i][0][2])%=MOD;
    cout << (ans+= f[K.size()][0][0]+ f[K.size()][0][1])%MOD;
    return 0;
}

