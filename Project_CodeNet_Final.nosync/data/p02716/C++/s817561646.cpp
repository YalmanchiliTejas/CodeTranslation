#include <bits/stdc++.h>

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast")
//1.0 * clock() / CLOCKS_PER_SEC

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const ll NN = 1e10 + 7;
const int N = 2e5 + 7;
const int M = 6;
const int mod = 1e9 + 7;
const ll inf = 1e18 + 7;
const dl rf = 1e-14;
const int B = sqrt(N);

int n;
int p[N];
ll a[N];
int l[N];
int r[N];
set < pair < ll , ll > > ss;

int get( int x )
{
    return (p[x] == x ? x : p[x] = get(p[x]));
}

void solve1()
{
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        p[i] = i;
        l[i] = r[i] = i;
        ss.insert({ a[i] , i });
    }
    ll ans = 0;
    for( int i = 1; i <= (n) / 2; i++ ){
        assert( !ss.empty() );
        auto x = *(--ss.end());
        ss.erase(--ss.end());
        ans += x.fi;
        int l1 = get( l[x.se] - 1 );
        int r1 = get( r[x.se] + 1 );
        if( l1 != 0 ){
            ss.erase({ a[l1] , l1 });
        }
        if( r1 != 0 ){
            ss.erase({ a[r1] , r1 });
        }
        int f = get( x.se );
        ll mz = a[l1] + a[r1] - x.fi;
        p[l1] = f;
        p[r1] = f;
        a[f] = mz;
        l[f] = min({ l[f] , l[l1] , l[r1] });
        r[f] = max({ r[f] , r[l1] , r[r1] });
        f = get( f );
        if( l[f] != 0 && r[f] != 0 ){
            ss.insert({ mz , f });
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int cghf = 1;//cin >> cghf;
    while( cghf-- ){
        solve1();
    }
}
