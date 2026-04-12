//Littleboy123 Template 1.7
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

//pragmas

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef unsigned long long int ull;
typedef long double ld;
typedef unsigned long long ull;

const long double pi = acos(-1.0);

#define FOR(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define FORN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define FORNE(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define TC(n) cout << "Case #" << (n) << ": "
#define DEBUG(x) cout << "DEBUG " << #x << ' ' << x << '\n';
#define MEM(a,b) memset((a), (b), sizeof((a)))
#define MAX(a,b) (a) = max((a), (b))
#define MIN(a,b) (a) = min((a), (b))
#define nl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void infile(){
    freopen("output.out", "r", stdin);
}

void outfile(){
    freopen("output.out", "w", stdout);
}

ll modex(ll a, ll b, ll mod){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll tmp = modex(a, b/2, mod);
    tmp = (tmp * tmp) % mod;
    if(b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}

//End of template

int main(){
    init();

    ll x;
    cin >> x;
    if(x >= 30){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
