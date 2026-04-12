#include <bits/stdc++.h>
#define filename "deque"
#define int long long
#define N 3005

using namespace std ;

int n , a[N] ;
bool chk[N][N] ;
int f[N][N] ;

void open()
{
    //freopen(filename".inp","r",stdin) ;
    //freopen(filename".out","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
}
void readin()
{
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        a[i] += a[i-1] ;
    }
}
int calc(int i ,int j)
{
    if (chk[i][j]) return f[i][j] ;
    if (i > j) return 0 ;
    chk[i][j] = 1 ;
    int &ans = f[i][j] ;
    ans = 0 ;
    ans = max(ans , a[j] - a[i-1] - calc(i+1 , j)) ;
    ans = max(ans , a[j] - a[i-1] - calc(i , j-1)) ;
    return ans ;
}
void process()
{
    cout << 2 * calc(1 , n) - a[n] ;
}
signed main()
{
    open() ;
    readin() ;
    process() ;
}