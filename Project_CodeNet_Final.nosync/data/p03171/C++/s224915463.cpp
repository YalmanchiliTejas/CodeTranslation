#include <bits/stdc++.h>
#define Nmax 3005

using namespace std;

const long long INF=1e18l;
ifstream f("1.in");
ofstream g("1.out");


long long dp[Nmax][Nmax];

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int L=n-1; L >= 0; L--)
    {
        for (int R=L; R <= n-1; R++)
            if(L==R) dp[L][R]=a[L];
            else dp[L][R]=max(a[R]-dp[L][R-1], a[L]-dp[L+1][R]);

    }

    cout << dp[0][n-1];

    return 0;
}
