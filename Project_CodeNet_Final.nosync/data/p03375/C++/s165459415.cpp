#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
using namespace std;
#define MAXN 3006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
//#define P 998244353
int n , P;
int S[MAXN][MAXN] , C[MAXN][MAXN];

int Pow( int x , int a ) {
	int ret = 1;
	while( a ) {
		if( a & 1 ) ret = ret * 1ll * x % P;
		x = x * 1ll * x % P , a >>= 1;
	}
	return ret;
}

int p2[MAXN];
void solve() {
	cin >> n >> P;
	S[0][0] = C[0][0] = 1 , p2[0] = 1;
	rep( i , 1 , n + 1 ) {
		C[i][0] = 1 , S[i][0] = 0;
		rep( j , 1 , i ) S[i][j] = ( S[i - 1][j - 1] + S[i - 1][j] * 1ll * j ) % P , C[i][j] = ( C[i - 1][j - 1] + C[i - 1][j] ) % P;
		p2[i] = p2[i - 1] * 2 % ( P - 1 );
	}
	int ans = 0;
	rep( i , 0 , n ) {
		int re = 0;
		rep( j , 0 , i ) re = ( re + S[i + 1][j + 1] * 1ll * Pow( 2 , ( n - i ) * 1ll * j % ( P - 1 ) ) ) % P;
		re = re * 1ll * Pow( 2 , p2[n - i] ) % P * C[n][i] % P;
		ans = ( ans + ( ( i & 1 ) ? P - re : re ) ) % P;
	}
	cout << ans << endl;
}

signed main() {
//	freopen("ex_A2.in","r",stdin);
//	freopen("out","w",stdout);
//	int T;cin >> T;while( T-- ) solve();
    solve();
}

