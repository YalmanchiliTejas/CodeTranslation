#include <bits/stdc++.h>
#include <climits>
//#define atclib
#ifdef atclib
    #include <atcoder/all>
#endif
//#define local
#ifdef local
    #include "dbg-macro/dbg.h"
#endif
//#define boost
#ifdef boost
    #include <boost/multiprecision/cpp_int.hpp>
#endif
#define p std::pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define vi std::vector<int>
#define pi std::pair<int, int>
#define mp std::make_pair
#define stdabs std::abs
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
#define oreq |=
#define npm next_permutation
#define Yes std::cout << "Yes" << std::endl
#define No std::cout << "No" << std::endl
#define YES std::cout << "YES" << std::endl
#define NO std::cout << "NO" << std::endl
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
template <class T> inline bool chmax(T& a__, T b__)
{
    if (a__ < b__) {
        a__ = b__;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T& a__, T b__)
{
    if (a__ > b__) {
        a__ = b__;
        return 1;
    }
    return 0;
}
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
ll extgcd(ll a, ll b, ll& x, ll& y);
ll nCr(ll n__, ll r__);
void stat();
template <typename T> T fact(T num__);
unsigned long long modpow(int x__, int n__, long long mod__);
template <typename T> void debug(const T& t__);
constexpr ll mod10_9p7 = 1000000000 + 7;

/**************************************************************/

int main()
{
    stat();
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ull ans = ULLONG_MAX;
/*old solution
    rep(i, max(x, y))
    {
        ull tmp = 2 * c * i;
        if (i < x) { tmp += (x - i) * a; }
        if (i < y) { tmp += (y - i) * b; }

        chmin(ans, tmp);
    }
    cout<<ans<<endl;
*/

chmin(ans,(ull)max(x,y)*2*c);
if(x>=y){
chmin(ans,(ull)(y*2*c)+(x-y)*a);
}else{

chmin(ans,(ull)(x*2*c)+(y-x)*b);
}

chmin(ans,(ull)(x*a)+(y*b));
cout<<ans<<endl;
    return 0;
}
/**************************************************************/
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (unsigned ll j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}

void stat(){

#ifdef atclib
    rep(i__, 2){std::cout << "atclib" << std::endl;
}
#endif
#ifdef local
rep(i__, 2) { std::cout << "local" << std::endl; }
#endif
#ifdef hacks
rep(i__, 2) { std::cout << "boost" << std::endl; }
#endif
}

ll nCr(ll n__, ll r__)
{
    ll num__ = 1;
    for (ll i__ = 1; i__ <= r__; i__++) {
        num__ = num__ * (n__ - i__ + 1) / i__;
    }
    return num__;
}

template <typename T> T fact(T num__)
{
    if (num__ == 1) { return 1; }
    return num__ * fact(num__ - 1);
}

unsigned long long modpow(int x__, int n__, long long mod__)
{
    long long ret__ = 1;
    for (long long i__ = 0; i__ < n__; ++i__) {
        ret__ = ret__ * x__ % mod__;
    }
    return ret__;
}

template <typename T> void debug(const T& t__)
{
#ifdef local
    dbg(t__);
#endif
}
