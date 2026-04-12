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
// #pragma GCC optimization ("O3")t
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

#define FOR(a,b,c) for(int (a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define FORN(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define FORNE(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
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
    freopen("walk.in", "r", stdin);
}

void outfile(){
    freopen("output.txt", "w", stdout);
}

ll modex(ll a, ll b, ll mod){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll tmp = modex(a, b/2LL, mod);
    tmp = (tmp * tmp) % mod;
    if(b & 1LL)
        tmp = (tmp * a) % mod;
    return tmp;
}

ll ex(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll tmp = ex(a, b/2LL);
    tmp = (tmp * tmp);
    if(b & 1LL)
        tmp = (tmp * a);
    return tmp;
}

//End of template

map<ll, int> pos;
ll cycle[100005];

int main(){
    init();

    ll n, x, m;
    cin >> n >> x >> m;
    cycle[1] = x;
    pos[x] = 1;
    ll sum = x;
    ll tmp;
    ll s, e;
    int flag = 0;
    FOR(i, 1, n){
        tmp = modex(cycle[i], 2, m);
        if(pos[tmp] != 0){
            flag = 1;
            s = pos[tmp];
            e = i;
            break;
        }
        cycle[i+1] = tmp;
        pos[tmp] = i+1;
        sum += tmp;
    }
    if(!flag){
        cout << sum << endl;
        return 0;
    }
    ll cycsum = 0;
    FORE(i, s, e){
        cycsum += cycle[i];
    }
    n -= e;
    ll div = n/(e-s+1LL);
    sum += div * cycsum;
    n %= (e-s+1);
    FOR(i, 0, n){
        sum += cycle[s+i];
    }
    cout << sum << endl;
    return 0;
}
