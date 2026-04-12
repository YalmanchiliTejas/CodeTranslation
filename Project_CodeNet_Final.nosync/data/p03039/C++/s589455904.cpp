/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──██████████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define int long long
#define read(a) int a; cin >> a;
#define readb(a, b) int a, b; cin >> a >> b;
#define readc(a, b, c) int a, b, c; cin >> a >> b >> c;
#define reads(s) string s; cin >> s;
#define readarr(a, n) int a[(n) + 1] = {}; fori (i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; fori (i, 1, n) {fori (j, 1, m) cin >> a[i][j];}

#define print(a) cout << a << endl;
#define printarr(a, n) fori (i, 1, n) cout << a[i] << " "; cout << endl;
#define printv(v) for (int i: v) cout << i << " "; cout << endl;
#define printmat(a, n, m) fori (i, 1, n) {fori (j, 1, m) cout << a[i][j] << " "; cout << endl;}
#define all(v) v.begin(), v.end()
#define sz(s) (int)(s.size())
#define pb push_back
#define fi first
#define se second
#define rz resize
#define fori(i, a, b) for (int i = (a); i <= (b); i++)
#define ford(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
#define setprec(x) cout << fixed << setprecision(x);
 
using namespace std;
using namespace __gnu_pbds; 
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair <int, int>> vpi;
typedef vector < vector <int> > vvi;
 
const int INF = 4e18;
const int mod = 1e9+7; 
const int N = 2e5;

vi fact(N + 1);

void meow()
{
    fact[0] = 1;
    fori (i, 1, N) fact[i] = fact[i-1] * i % mod;
}

int power (int x, int y) 
{ 
    int res = 1;
    x = x % mod; 
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % mod; 
        y = y>>1; 
        x = (x*x) % mod;   
    } 
    return res; 
}

int inv (int n) 
{ 
    return power(n, mod-2); 
} 

int ncr (int n, int r)
{
    return fact[n] * inv(fact[n-r]) % mod * inv(fact[r]) % mod;
}
     
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //start from here

    meow();
    readc(n, m, k)

    int x = ncr(n*m - 2, k-2);

    int ans = 0;

    fori (i, 1, n)
    {
        fori (j, 1, m)
        {
            int l = j - 1;
            int r = m - j;
            int up = i - 1; 

            up = up * (up + 1) / 2 % mod;
            l = l * (l + 1) / 2 % mod; r = r * (r + 1) / 2 % mod;

            ans += l % mod;  ans %= mod;
            ans += (l + r) % mod * (i - 1) % mod; ans %= mod;
            ans += up * m % mod; ans %= mod;
        }
    }

    print(ans * x % mod)

    return 0;
}
