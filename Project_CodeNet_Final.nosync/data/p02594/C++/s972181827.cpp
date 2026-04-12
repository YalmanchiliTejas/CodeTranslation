#include "bits/stdc++.h"
 
using namespace ::std;
 
#define all(x)  x.begin(),x.end()
#define Unique(x) x.erase(unique(all(x)), x.end())
 
template< class T > T SQR(T N) {return (T) N * N;}
template< class T > double DIST(T a, T b) {return 1.0 * sqrt(SQR(double(a)) + SQR(double(b)));}
template< class T > bool CROSS(pair< T,T > a, pair< T,T > b, pair< T,T > c) {return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);}
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int,int > pi;
 
int px[] = {0, 1, -1, 0, -1, -1, 1, 1};
int py[] = {1, 0, 0, -1, -1, 1, -1, 1};
 
double EPS = 1e-9;
double PI = acos(-1);
double GR = 1.6180339887498948;

vector< int >Pr;

inline void Seive()
{
    bool a[15007]{};
    Pr.push_back(2);
    for(int i = 4; i<=15005; i += 2) a[i] = 1;
    for(ll i = 3; i * i <(1505); i += 2) if(!a[i]) {for(ll j = i * i; j <= 15005; j = j + 2 * i) a[j] = 1;}
    for(int i = 3; i<= 15005; i += 2) if(!a[i]) Pr.push_back(i);
}
 
inline ll power(ll a, ll p, ll mod)
{
    ll x = a, res = 1;
 
    while(p)
    {
        if(p&1) res = (res * x)%mod;
        p /= 2, x = (x * x)%mod;
    }
    return res;
}
 
int F[207];
 
inline void Fail(string str)
{
    string s = str;
    reverse(all(s));
 
    s = s + "#" + str;
 
    int len = s.length();
 
    for(int i = 1; i<len; ++i)
    {
        int j = F[i - 1];
        while (j > 0 and s[i] != s[j])
            j = F[j - 1];
         if(s[i] == s[j]) ++j;
         F[i] = j;
    }
}
 
// ll Pow[500007];
// ll bit[500007];
// ll mod = 998244353LL;
 
// struct BIT
// {
//     inline void UPDATE(int idx, int n, int val)
//     {
//         for(int i = idx; i<=n; i += (i&-i))
//             bit[i] = (bit[i] + (Pow[idx] * val)%mod)%mod;
//     }
 
//     inline ll Sum(int idx)
//     {
//         ll ss = 0;
//         for(int i = idx; i; i -= (i & -i))
//             ss = (ss + bit[i])%mod;
//         return ss;
//     }
// };

// inline int SMALL_GIANT(ll a, ll rem, ll mod)
// {
//     a %= mod, rem %= mod;

//     ll k = 1, step = 0, gcd;
//     while((gcd = __gcd(a, mod)) > 1)
//     {
//         if(k == rem) return step;
//         if(rem%gcd) return -1;
//         rem /= gcd, mod /= gcd, ++step;
//         k = (k * (a/gcd))%mod;
//     }

//     int n = sqrt(mod) + 1;
//     unordered_map< int,int >mp;

//     ll xx = 1, cur = rem, xxx = k;
//     for(int i = 0; i<n; ++i) xx = (xx * a)%mod;

//     for(int q = 0; q <= n; ++q)
//         mp[cur] = q, cur = (cur * a)%mod;

//     for(int p = 1; p <=n; ++p)
//     {
//         xxx = (xxx * xx)%mod;
//         if(mp[xxx]) return p * n - mp[xxx] + step;
//     }
//     return -1;
// }

//vector< int >graph[200000];


int main()
{
    cin.tie(0); cout.tie(0);
 
    int n, m, c, d, a, b, k;
    int test;
    
    // scanf("%d", &test);
    // for(int t = 1; t<=test; ++t)
    // {
    //     scanf("%d%d", &k, &b);


    // }

    scanf("%d", &n);
    if(n >= 30) puts("Yes");
    else puts("No");
}