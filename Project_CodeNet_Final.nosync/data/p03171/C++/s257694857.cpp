#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(a, b, i) for(int i=a; i<b; i++)
#define RFOR(a, b, i) for(int i=a; i>=b; i--)
#define PB push_back
#define MP make_pair
#define MOD 1e9+7
#define newline cout<<"\n"

const int nax = 3005;

ll dp[nax][nax];
void initialize()
{
    FOR(0, nax, i) FOR(0, nax, j) dp[i][j]=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vector<ll> v(n);
    initialize();

    FOR(0, n, i) cin>>v[i];

    // dp[i][j] means value of X-Y when first i elements from the left and j elements from right are removed
    // dp[0][n-1] is the answer

    RFOR(n-1, 0, L)
    {
        FOR(L, n, R)
        {
            if(L==R)
            {
                dp[L][R] = v[L];
            }
            else
            {
                dp[L][R] = max(v[L]-dp[L+1][R], v[R]-dp[L][R-1]);
            }
            
        }
    }
    cout<<dp[0][n-1]<<"\n";

    return 0;
}