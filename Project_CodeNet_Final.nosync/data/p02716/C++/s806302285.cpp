/**
 *      ///----- My Info -----///
 *      Clock: nowl
 *      Code by: Ernesto Abreu
 *      Codeforces User: Ernest0_0Abreu
 *      Country: Cuba
 *      E-mail: ernestoabreup@gmail.com
 *      �CopyRight
**/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
        ///----- My Template -----///
///=====================================================================================================================
/// Red-Black Tree
// #include <ext/pb_ds/assoc_container.hpp>  // .find_of_order(x); .order_of_key(x);
// using namespace __gnu_pbds;
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > indexed_set;
/// Typedef
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
/// Function
#define pi (acos(-1))
#define lg2(x) 31-__builtin_clz(x)
#define lgx(x,b) log(b)/log(x)
/// Macros
#define fst first
#define scd second
#define pb push_back
#define left (node<<1)
#define right ((node<<1)+1)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
/// Debug
#define _end cout << "\n"
#define debug(x) cerr << #x << " = " << x << " "
/// Constant
const int MAXN = 2e5+7;
const int MOD = 1e9+7;
const ull BASE = 311;
const ld EPS = 1e-9;
const int INF = ((1<<30)-1);
const ll INFLL = ((1ll<<62ll)-1ll);
/// Hash Prime Numbers: 2, 277, 293, 307, 331, 337, 1009, 2027;
/// Module Prime Numbers: 3, 998244353, 1000000007, 1000000009, 1000000021, 1000000033;
///=====================================================================================================================
#define int long long
        ///----- My code -----///

int ar[MAXN], dp[MAXN][4];

int32_t main (){

    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout.setf(ios::fixed);cout.precision(0);
//  freopen("a.in", "r", stdin);

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> ar[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j =  0; j <= 2; j++){
            dp[i][j] = -INFLL;
        }
    }

    if(N&1){
        dp[0][0] = 0;
        dp[1][0] = ar[1], dp[2][0] = ar[2];
        for(int i = 3; i <= N; i++){
            dp[i][0] = dp[i-2][0]+ar[i];
            dp[i][1] = max(dp[i][1], dp[i-3][0]+ar[i]);
            if(i-2 >= 3) dp[i][1] = max(dp[i][1], dp[i-2][1]+ar[i]);
            if(i-4 >= 1) dp[i][2] = max(dp[i][2] , dp[i-4][0]+ar[i]);
            if(i-3 >= 4) dp[i][2] = max(dp[i][2] , dp[i-3][1]+ar[i]);
            if(i-2 >= 5) dp[i][2] = max(dp[i][2] , dp[i-2][2]+ar[i]);
        }
        int ans = -INFLL;
        ans = max(ans , dp[N-2][0]);
        ans = max(ans , max(dp[N-1][0] , dp[N-1][1]) );
        ans = max(ans , max(dp[N][1] , dp[N][2]) );
        cout << ans;
    }
    else{
        dp[1][0] = ar[1], dp[2][0] = ar[2];
        for(int i = 3; i <= N; i++){
            dp[i][0] = dp[i-2][0]+ar[i];
            if(i-3 >= 1) dp[i][1] = max(dp[i][1], dp[i-3][0]+ar[i]);
            if(i-2 >= 4) dp[i][1] = max(dp[i][1], dp[i-2][1]+ar[i]);
        }
        int ans = max(dp[N-1][0] , max(dp[N][1] , dp[N][0]));
        cout << ans;
    }

    return 0;
}
/*
Test case:
27
18 -28 18 28 -45 90 -45 23 -53 60 28 -74 -71 35 -26 -62 49 -77 57 24 -70 -93 69 -99 59 57 -49
*/

