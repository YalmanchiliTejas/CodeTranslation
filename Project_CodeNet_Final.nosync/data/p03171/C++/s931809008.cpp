#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long

const int N = 3e3 + 5;
int n;
int a[N];
int dp[N][N];

/// dp[i][j] là số điểm cao nhất mà khi tới trạng thái [i , j] thì thằng đi sẽ được nhiều điểm nhất.

main()
{
    //freopen("L.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    FOR(i , 1 , n)
    {
        cin >> a[i];
        sum += a[i];
    }
    FOR(i , 1 , n)
        dp[i][i] = a[i];
    FOR(i , 2 , n)
        dp[i - 1][i] = max(a[i - 1] , a[i]);
     FOR(r , 1 , n)
        FORD(l , r - 2 , 1)
            dp[l][r] = max(min(dp[l + 1][r - 1] , dp[l + 2][r]) + a[l] , min(dp[l + 1][r - 1] , dp[l][r - 2]) + a[r]);
    cout << dp[1][n] - (sum - dp[1][n]);
}
