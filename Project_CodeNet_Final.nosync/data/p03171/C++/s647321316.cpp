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

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo INT_MAX

const int N = 3e3 + 5;
ll n , res;
ll a[N];
ll dp[N][N];
/// dp[i][j] là số điểm lớn nhất của người chơi thứ 1 có thẻ nhận được nếu khởi đầu trong đoạn [i , j]

int main()
{
    //freopen("L.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
    {
        cin >> a[i];
        res += a[i];
    }
    FOR(i , 1 , n)
        dp[i][i] = a[i];
    FOR(i , 1 , n - 1)
        dp[i][i + 1] = max(a[i] , a[i + 1]);
    FOR(r , 3 , n)
        FORD(l , r - 2 , 1)
            dp[l][r] = max(min(dp[l + 2][r] , dp[l + 1][r - 1]) + a[l] , min(dp[l][r - 2] , dp[l + 1][r - 1]) + a[r]);
    cout << dp[1][n] - (res - dp[1][n]) << endl;
}
