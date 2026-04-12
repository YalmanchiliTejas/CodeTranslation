#include<bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    int K;
    cin>>N>>K;

    int length_N = (int) N.size();
    vector<vector<vector<long long>>> dp(length_N + 5,vector<vector<long long>>(4,vector<long long>(2,0)));

    dp[0][0][0] = 1;
    for(int i = 0; i < length_N; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                int nd = N[i] - '0';//見る桁の値を取得
                for(int d = 0; d < 10; d++)
                {
                    int ni = i+1;
                    int nj = j;
                    int nk = k;
                    if(d != 0)nj++;
                    if(nj > K) continue;
                    if(k == 0)
                    {
                        if(d > nd)continue;
                        if(d < nd)nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
            
        }
    }
    int ans = dp[length_N][K][0] + dp[length_N][K][1];
    cout << ans <<endl;
    cin>>N;
    return 0;
}