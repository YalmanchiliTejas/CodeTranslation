// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
string x ;
int k,n;
ll dp[101][4][2];
ll solve (int cur = 0 , bool ex = 0 , int d =0 )
{
    if (cur == n )return d == k ;
    if (d > k )return 0;
    ll &ret = dp[cur][d][ex];
    if (~ret)return ret ;
    ret =0 ;
    int mx = x[cur] - '0';
    if (ex)mx = 9;
    for (int i =0 ; i <= mx ;i++)
    {
        ret += solve(cur + 1 , (ex | (i < mx )) , d + (i > 0) );
    }
    return ret ;
}
int main()
{
    memset(dp , -1 ,sizeof dp);
    cin >> x >> k ;
    n = SZ(x)  ;
    cout << solve() ;

}
