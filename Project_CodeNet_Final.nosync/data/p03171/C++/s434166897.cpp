#include <iostream>
#define NMAX 3000

using namespace std;

int n;
long long v[NMAX+10], dp[NMAX+10][NMAX+10];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int len=0; len<n; len++)
        for(int st=1; st<=n-len+1; st++)
            {   int dr = st + len;
                dp[st][dr] = max(v[st] - dp[st+1][dr], v[dr] - dp[st][dr-1]);
            }
    cout << dp[1][n] << '\n';
    return 0;
}
