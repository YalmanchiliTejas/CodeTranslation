//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
   
//#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair                                     
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
//#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, m;
ll t[4 * N], add[4 * N];
vector <pii> g[N];

inline void push (int v, int tl, int tr) {
   if (!add[v]) return;
   t[v] += add[v];
   if (tl != tr) {
      add[v + v] += add[v];
      add[v + v + 1] += add[v];
   }
   add[v] = 0;
}

void upd (int l, int r, ll val, int v = 1, int tl = 0, int tr = n) {
   push (v, tl, tr);
   if (tl > r || tr < l) return;
   if (l <= tl && tr <= r) {
      add[v] = val;
      push (v, tl, tr);
      return;
   }
   int tm = tl + tr >> 1;
   upd (l, r, val, v + v, tl, tm);
   upd (l, r, val, v + v + 1, tm + 1, tr);
   t[v] = min (t[v + v], t[v + v + 1]);
}

ll get (int l, int r, int v = 1, int tl = 0, int tr = n) {
   push (v, tl, tr);
   if (tl > r || tr < l) return inf;
   if (l <= tl && tr <= r) return t[v];
   int tm = tl + tr >> 1;
   return min (get (l, r, v + v, tl, tm), get (l, r, v + v + 1, tm + 1, tr));
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     

inline void Solve () {
   cin >> n >> m;
   ll sum = 0;
   for (int i = 1, l, r, a; i <= m; i ++) cin >> l >> r >> a, g[r + 1].pb ({l, a}), sum += a;
   for (int i = 1; i < 4 * N; i ++) t[i] = inf;
   upd (0, 0, -inf);
   for (int i = 1; i <= n + 1; i ++) {
      for (auto it : g[i])
         upd (0, it.F - 1, it.S);
      upd (i, i, t[1] - inf);
   }   
   cout << sum - t[1];
}

main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
                          