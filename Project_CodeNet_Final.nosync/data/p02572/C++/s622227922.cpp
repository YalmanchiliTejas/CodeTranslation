/****************### With The name of ALLAH, most Gracious, most Compassionate ###****************/

/**============================================================================**\
|   Author      : Md Jubayer Hossen Jame
|   Study       : CSE, BRUR
|   Today       : 04 September, 2k20
|   Source      : AtCoder Online Judge
|   Problem link: https://atcoder.jp/contests/abc177/tasks/abc177_c
|   Algorithm   :
|
\**============================================================================**/

#include "bits/stdc++.h"
using namespace std;

#define FI                    freopen("input.txt", "r", stdin)
#define FO                    freopen("output.txt", "w", stdout)
#define FasterIO              ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long             ll;
typedef unsigned long long    ull;
typedef unsigned int          ui;

#define mem(x,y)              memset(x,y,sizeof(x));
#define pii                   pair<int,int>
#define mk                    make_pair
#define ff                    first
#define ss                    second
#define pb                    push_back
#define ppb                   pop_back
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
#define for0(i, n)            for (int i = 0; i < (int)(n); ++i)
#define endl                  '\n'

const double PI = acos(-1.0);

#define gcd(a,b)              __gcd(a,b)
#define lcm(a,b)              (a*(b/gcd(a,b)))

///Direction Array
// 4 Direction - DOWN, UP, RIGHT, LEFT
int dx4[]= {+1, -1, +0, +0};
int dy4[]= {+0, +0, +1, -1};
#define isValid(a, b, R, C)   (0 <= a && a < R) && (0 <= b && b < C)
int dx8[]= {+0, +0, +1, -1, -1, +1, -1, +1};
int dy8[]= {-1, +1, +0, +0, +1, +1, -1, -1};

///Knight Moves
int dr[] = {-1, 1, -2, -2, -1, 1, 2, 2};
int dc[] = {-2, -2, -1, 1, 2, 2, 1, -1};
/**************************************************************************************************/

const int MOD = 1e9 + 7;

void test_case()
{
    int n;
    cin >> n;

    vector <ll> vc(n+1), cum(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> vc[i];
        cum[i] = cum[i-1] + vc[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans = ( (ans % MOD) + ( ( ( cum[n] - cum[i] ) % MOD ) * vc[i] ) % MOD ) % MOD;
    }
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //FI;
    //FO;
#endif // ONLINE_JUDGE
    //FasterIO

    int T = 1;
    //cin >> T;
    for(int tc = 1; tc <= T; ++tc)
    {
        //cout << "Case #" << tc << ":" << endl;
        test_case();
    }
    return 0;
}
