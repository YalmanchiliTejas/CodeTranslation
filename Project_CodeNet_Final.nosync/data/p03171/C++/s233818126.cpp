#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;
typedef double ld;
typedef pair<int,int> p2;
typedef pair<p2,int> p3;
typedef vector<ll> vi;
const ll Mod = 7 + 1e9;
const ll INF32 = 5 + 2e9;
const ll INF64 = 1 + 1e18;
const ll MAX = 5+ 3e3;

int N,K,a[MAX];
ll dp[MAX][MAX];


int main()
{
    cin >> N ;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    for(int i=N;i>=1;i--)
        for(int j=i;j<=N;j++)
        {
            bool turn = ( N - (j-i+1) )%2;
            dp[i][j] = turn ? min( dp[i+1][j] - a[i] ,dp[i][j-1] - a[j] ) : max( dp[i+1][j] + a[i] ,dp[i][j-1] + a[j] );
        }
    cout << dp[1][N] << endl;
    return 0;
}
