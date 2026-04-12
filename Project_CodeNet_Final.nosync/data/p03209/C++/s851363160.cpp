#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 5e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp1[MAXN], dp2[MAXN];

ll solve(ll n, ll x){
	if(x == 0) return 0;
	if(x == dp1[n]) return dp2[n];
	if(n == 0) return x;
	if(1 + dp1[n - 1] >= x) return solve(n - 1, x - 1);
	return dp2[n - 1] + 1 + solve(n - 1, x - (dp1[n - 1] + 2));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp1[0] = 1;
	dp2[0] = 1;
	for(int i = 1; i < MAXN; i++){
		dp1[i] = 3 + 2 * dp1[i - 1];
		dp2[i] = 1 + 2 * dp2[i - 1];
	}
	ll n, x;
	cin >> n >> x;
	cout << solve(n, x);
	return 0;
}


/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/

