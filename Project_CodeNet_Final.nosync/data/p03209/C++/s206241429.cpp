//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<ll> sz, p;

ll f(ll n, ll x){
    if(n == 0) return 1;
    if(x == sz[n]) return p[n];
    ll sum = 0;
    if(x > 1) sum += f(n - 1, min(x - 1, sz[n - 1]));
    if(x > sz[n] / 2 + 1) sum += f(n - 1, min(x - (sz[n] / 2 + 1), sz[n - 1]));
    if(x >= sz[n] / 2 + 1) sum += 1;
    return sum;
}

int main(){
    StarBurstStream

    ll n, x;
    cin >> n >> x;

    sz.resize(51);
    p.resize(51);
    sz[0] = 1; p[0] = 1;
    for(int i = 1; i <= 50; i++) sz[i] = sz[i - 1] * 2 + 3, p[i] = p[i - 1] * 2 + 1;
    cout << f(n, x) << "\n";

    return 0;
}