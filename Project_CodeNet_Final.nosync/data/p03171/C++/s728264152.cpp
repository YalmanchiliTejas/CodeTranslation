#include <iostream>

using namespace std;

long long dp[3007][3007];
int tab[3007];

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> dp[i][i];
        tab[i]=dp[i][i];
    }
    cout << "\n";
    for(int i=1; i<=N; i++)
        for(int j=i-1; j>0; j--)
            dp[j][i]=max(tab[j]-dp[j+1][i], tab[i]-dp[j][i-1]);
    /*
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << dp[1][N];
}