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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e4 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

const ll LOG = 130;

ll dp[MAXN][110][2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str k;
	ll D;
	cin >> k >> D;
	ll n = k.size();
	dp[0][0][1] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < D; j++){
			for(int dig = 0; dig < 10; dig++){
				if(dig < (k[i] - '0')){
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][1];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
				} else if ( dig == (k[i] - '0') ){
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][1] += dp[i][j][1];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
					dp[i + 1][ (j + dig) % D ][1] %= MOD;
				} else {
					dp[i + 1][ (j + dig) % D ][0] += dp[i][j][0];
					dp[i + 1][ (j + dig) % D ][0] %= MOD;
				}
			}
		}
	}
	
	cout << (dp[n][0][1] + dp[n][0][0] + 1000000006) % MOD;
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
