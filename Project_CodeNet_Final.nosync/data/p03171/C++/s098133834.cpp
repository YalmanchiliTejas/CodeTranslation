#include <iostream>
#include <vector>

using namespace std;

vector < vector<long long> > dp(3005, vector< long long>(3005, 0));
vector <long long> v(3005);

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        dp[i][i] = v[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dp[i][j] = max(v[j] - dp[i][j + 1], v[i] - dp[i - 1][j]);
        }
    }

    cout << dp[ n - 1 ][ 0 ];

    return 0;
}
