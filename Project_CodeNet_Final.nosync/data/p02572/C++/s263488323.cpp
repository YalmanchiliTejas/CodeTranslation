#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <fstream>
#include <unordered_map>
#include <time.h>
using namespace std;
#define ms(a, x) memset(a, x, sizeof(a))
#define fore(i, a, n) for (ll ll i = a; i < n; i++)
#define ford(i, a, n) for (ll ll i = n - 1; i >= a; i--)
#define si(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define ss(a) scanf("%s", a);
#define debug(a) cout << a << endl
#define pr(a) printf("%d ", a)
#define endl '\n'
#define pi acos(-1.0)
#define tr t[root]
#define IO ios::sync_with_stdio(false), cin.tie(0)
#define ull unsigned long long
#define py puts("Yes")
#define pn puts("No")
#define pY puts("YES")
#define pN puts("NO")
#define re(i, a, b) for (int i = a; i <= b; ++i)
#define de(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define ls(x) x.resize(unique(all(x)) - x.begin())
const double eps = 1e-3;
inline int sgn(const double &x) { return x < -eps ? -1 : x > eps; }
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 0x3f3f3f3f;
template <class T>
inline void cmin(T &a, T b) { ((a > b) && (a = b)); }
template <class T>
inline void cmax(T &a, T b) { ((a < b) && (a = b)); }
long long PRIMES[223] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409};
const int maxn = 2e5 + 5;
const ll mode = 1e9 + 7;
//--------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll GC(pll x)
{
    ll a = x.first;
    ll b = x.second;
    return b ? gcd(b, a % b) : a;
}
ll Pow(ll a, ll b)
{
    ll sum = 1;
    a = a % mode;
    b = b % (mode - 1);
    while (b)
    {
        if (b & 1) //判断是否是奇数，是奇数的话将多出来的数事先乘如sum
            sum = sum * a % mode;
        b >>= 1;
        a = a * a % mode; // 不断的两两合并再取模，减小a和b的规模
    }
    return sum;
}
ll mul(ll a, ll b)
{
    ll ans = 0;
    a %= mode, b %= mode;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mode;
        a = (a * 2) % mode;
        b >>= 1;
    }
    return ans;
}
//-----------------------------------------------------------------------------------------
ll a[maxn];
int main()
{
    IO;
    int n;
    cin>>n;
    ll sum=0;
    re(i,1,n)cin>>a[i],sum+=a[i],sum%=mode;
    ll ans=0;
    re(i,1,n-1)sum=(sum-a[i]+mode)%mode,ans=(ans+sum*a[i]%mode)%mode;
    cout<<ans<<endl;

}