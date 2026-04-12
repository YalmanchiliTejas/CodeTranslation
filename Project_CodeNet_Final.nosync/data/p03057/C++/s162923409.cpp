#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)//  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<ll> A;
ll dp[MAXN], sm[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	str s;
	cin >> s;
	
	ll cnt = 1;
	for(int i = 1; i < m; i++){
		if(s[i] == s[i - 1]) cnt ++;
		else {
			A.pb(cnt);
			cnt = 1;
		}
	}
	A.pb(cnt);
	if(A.size() == 1){
		//debug("S");
		dp[1] = 1;
		dp[2] = 0;
		sm[1] = 1;
		sm[2] = 1;
		for(int i = 3; i <= n; i++){
			dp[i] = sm[i - 2];
			sm[i] = (dp[i] + sm[i - 1]) % MOD;
		}
		ll ans = 1;
		for(int len = 1; len <= n - 1; len ++){
			ans += (len + 1ll) * dp[n - len];
			ans %= MOD;
		}
		cout << ans;
		return 0;
		/////
	}
	
	ll mx;
	
	if(A[0] % 2 == 0) mx = A[0] + 1;
	else mx = A[0];
	for(int i = 2; i + 1 < A.size(); i += 2){
		if(A[i] % 2 == 1) mx = min(mx, A[i]);
	}
	debug(mx);
	dp[0] = 0;
	dp[1] = 1;
	dp[3] = 1;
	for(int i = 5; i <= n; i++){
		dp[i] = dp[i - 2] + dp[i - 2];
		if(i >= mx + 3) dp[i] -= dp[i - mx - 3];
		dp[i] %= MOD;
	}
	//debug(dp[1]);
	//debug(dp[3]);
	ll ans = 0;
	for(ll len = 1; len <= min(n-1ll, mx); len += 2){
		ans += ((len + 1ll) * dp[n - len]);
		ans %= MOD;
	}
	cout << ((ans % MOD) + MOD)%MOD;
	
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

