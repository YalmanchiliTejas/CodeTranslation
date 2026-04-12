#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
 
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
typedef vector < pii > vpii;
typedef vector < pll > vpll;
 
typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ms;

#define all(v)     (v).begin(), (v).end()
#define srt(v)    sort (all (v))
 
#define pb push_back
#define mp make_pair

#define fill (x, y)    memset(x, y, sizeof(x))
#define clr(a)    fill(a, 0)
// #define endl '\n'
 
#define PI 3.14159265358979323
 
const int Maxn = 2e5 + 2;
const int Mod = 1e9 + 7;
#define trace1(x1)                    cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)                cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)            cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;
 
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}
 
template<typename T, typename T1>
T mod(T x, T1 p) {
    x %= p;
    if (x < 0)
        x += p;
    return x;
}
 
// // int inv[Maxn], ifact[Maxn], fact[Maxn];
// template<typename T>
// T inverse(T x, T p) 
// {
//     x = mod(x, p);
//     if (x == 1)
//         return x;
//     return mod((1LL * (-p / x) * (inv[p % x] % p)) , p); 
//     // Since inverse of p % x is already calculated.
// }
 
// ll NcR(ll n, ll r) 
// {
//     int ret = (1LL * ifact[n - r] * ifact[r]) % Mod ;
//     ret = (1LL * ret * fact[n]) % Mod;
//     return ret;
// }
 
void leastPrimeFactor(vector<int>&least_prime, int n) 
{ 
    least_prime[1] = 1;  
    for (int i = 2; i <= n; i++) 
    { 
        if (least_prime[i] == 0) 
        { 
            least_prime[i] = i; 
            for (int j = 2*i; j <= n; j += i) 
                if (least_prime[j] == 0) 
                   least_prime[j] = i; 
        } 
    } 
}
 
// ifact[0] = 1;
// for(int i = 1; i < Maxn; i++) 
// {
//     inv[i] = inverse(i, Mod);
//     ifact[i] = (1LL * ifact[i - 1] * inv[i]) % Mod;
// }
 
// int fact[Maxn];
// fact[0] = 1;
// for(int i = 1; i < Maxn; i++) 
// {
//     fact[i] = 1LL * fact[i - 1] * i % Mod;
// }
 

// struct dat {
//     ll sum, pref, suff, ans;
// };

// dat make_dat(ll val) {
//     dat res;
//     res.sum = val;
//     res.pref = res.suff = res.ans = max((ll)0, val);
//     return res;
// }

// dat t[4*Maxn];

// dat combine(dat l, dat r) 
// {
//     dat res;
//     res.sum = l.sum + r.sum;
//     res.pref = max(l.pref, l.sum + r.pref);
//     res.suff = max(r.suff, r.sum + l.suff);
//     res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
//     return res;
// }
 
// void build(vector<ll>& a, int v, int tl, int tr) 
// {
//     if (tl == tr) 
//         t[v] = make_dat((ll)a[tl]);
//     else 
//     {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = combine(t[v*2], t[v*2+1]);
//     }
// }

// void update(int v, int tl, int tr, int pos, ll new_val) 
// {
//     if (tl == tr) 
//         t[v] = make_dat(new_val);
//     else 
//     {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = combine(t[v*2], t[v*2+1]);
//     }
// }

// dat query(int v, int tl, int tr, int l, int r) 
// {
//     // cout << l << " " << r << " " << tl << " " << tr << endl;
//     if (l > r) 
//         return make_dat(0);
//     if (l == tl && r == tr) 
//         return t[v];
//     int tm = (tl + tr) / 2;
//     return combine(query(v*2, tl, tm, l, min(r, tm)), 
//                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
// }

// void push(ll v) 
// {
//     t[v*2] += lazy[v];
//     lazy[v*2] += lazy[v];
//     t[v*2+1] += lazy[v];
//     lazy[v*2+1] += lazy[v];
//     lazy[v] = 0;
// }

// void update(int v, int tl, int tr, int l, int r, ll addend) 
// {
//     if (l > r) 
//         return;
//     if (l == tl && tr == r) 
//     {
//         t[v] += addend;
//         lazy[v] += addend;
//     } 
//     else 
//     {
//         push(v);
//         int tm = (tl + tr) / 2;
//         update(v*2, tl, tm, l, min(r, tm), addend);
//         update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
//         t[v] = combine(t[v*2], t[v*2+1]);
//     }
// }

// ll query(int v, int tl, int tr, int l, int r) 
// {
//     // cout << l << " " << r << " " << tl << " " << tr << endl;
//     if (l > r) 
//         return make_dat(0);
//     if (l <= tl && r >= tr) 
//         return t[v];
//     push(v);
//     int tm = (tl + tr) / 2;
//     return combine(query(v*2, tl, tm, l, min(r, tm)), 
//                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
// }

// vi ps;

// int rec(int l, int r)
// {
//     if(l==r)
//         return 0;
//     int cur = rec(l,(l+r)/2) + rec((l+r)/2+1,r);
//     if((ps[r+1]-ps[(l+r)/2+1])%10+(ps[(l+r)/2+1]-ps[l])%10>=10)
//         cur++;
//     // cout << l << " " << r << cur << endl;
//     return cur;
// }

vector<vpii> adj;

int main() 
{
    FAST_IO;
    // int nt;
    // cin >> nt;
    // // dir = {{-1,0},{1,0},{0,1},{0,-1}};
    // for(int ze = 0 ; ze < nt ; ze++)
    // {

    int x;
    cin >> x;
    if(x>=30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    // }
}
