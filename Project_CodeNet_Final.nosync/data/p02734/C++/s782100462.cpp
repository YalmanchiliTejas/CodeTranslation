#include <bits/stdc++.h>

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast")
//1.0 * clock() / CLOCKS_PER_SEC

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int NN = 1e6 + 7;
const int N = 3e3 + 7;
const int M = 20;
const int mod = 998244353;
const ll inf = 1e18 + 7;
const dl rf = 1e-14;

ll n,s;
ll a[N];
ll d[N][N];
ll sum[N][N];

void solve1()
{
    cin >> n >> s;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        d[i][a[i]] = i;
    }
    ll ans = 0;
    for( int i = 1; i <= n; i++ ){
        for( int j = a[i]; j <= s; j++ ){
            d[i][j] = ( d[i][j] + sum[i - 1][j - a[i]] ) % mod;
        }
        for( int j = 0; j <= s; j++ ){
            sum[i][j] = ( sum[i - 1][j] + d[i][j] ) % mod;
        }
        ans = ( ans + d[i][s] * (n - i + 1) % mod ) % mod;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); srand(time(0));
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int cghf = 1;//cin >> cghf;
    while( cghf-- ){
        solve1();
    }
}
