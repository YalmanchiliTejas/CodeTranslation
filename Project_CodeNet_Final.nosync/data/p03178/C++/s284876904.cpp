#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("p.in");
ofstream fout("p.out");

long long MOD = 1e9+7;

int main()
{
    char s[10001];
    cin>>s;
    int d;
    cin>>d;

    long long dp[100001][101][2];

    dp[0][0][0]=1;
    for(int i = 0; s[i] != '\0'; i++)
        {
            int cif = s[i] - '0';
            for(int j = 0; j < d ; j++)
                for(int k = 0; k < 10; k++)
                    {
                        dp[i+1][(j+k)%d][1] = (dp[i+1][(j+k)%d][1] + dp[i][j][1]) % MOD;
                        if(cif == k)
                            {
                                dp[i+1][(j+k)%d][0] = ( dp[i+1][(j+k)%d][0] + dp[i][j][0] ) % MOD;
                            }
                        else if(cif > k)
                                {
                                    dp[i+1][(j+k)%d][1] = (dp[i+1][(j+k)%d][1] + dp[i][j][0]) % MOD;
                                }
                    }
        }

    cout<<(dp[strlen(s)][0][0] + dp[strlen(s)][0][1] - 1 + MOD) % MOD;

    return 0;
}
