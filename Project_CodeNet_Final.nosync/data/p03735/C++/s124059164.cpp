# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const ll md = 101111111111;
const int xn = 2e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD[4] = {1000000009, 1000000007, 987654319, 999999937};
const int TM = 3;
const int BASE = 257;

ll n, ans = INF;
pll num[xn], a, b, c, d;
set <pll> st[2];

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> num[i].A >> num[i].B;
    for (int i = 0; i < n; ++ i) if (num[i].A > num[i].B) swap(num[i].A, num[i].B);
    sort(num, num + n);
    for (int i = 0; i < n; ++ i) st[0].insert({num[i].A, i}), st[1].insert({num[i].B, i + n});
    a = *st[0].begin();
    b = *prev(st[0].end());
    c = *st[1].begin();
    d = *prev(st[1].end());
    ans = (b.A - a.A) * (d.A - c.A);
    for (int i = 0; i < n; ++ i){
    	st[0].erase({num[i].A, i}), st[1].insert({num[i].A, i});
    	st[1].erase({num[i].B, i + n}), st[0].insert({num[i].B, i + n});
    	a = *st[0].begin();
	    b = *prev(st[0].end());
	    c = *st[1].begin();
	    d = *prev(st[1].end());
	    ans = min(ans, (b.A - a.A) * (d.A - c.A));
	}
	cout << ans << endl;
	
    return 0;
}
