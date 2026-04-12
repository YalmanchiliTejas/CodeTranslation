#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)

const ll N = 123456;
const ld eps = 1e-6;
const ld pi = 3.1415926535;
const int MAX = 123456;
const ll mod = 1e9 + 7;

ll a[N];

ll dp[3333][3333];

ll DP(int t , int l , int r) {
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	ll temp;
	if(t == 1) {
		temp = DP(1 - t , l , r - 1) + a[r];
		temp = max(temp , DP(1 - t , l + 1 , r) + a[l]);
	}
	else {
		temp = DP(1 - t , l , r - 1) - a[r];
		temp = min(temp , DP(1 - t , l + 1 , r) - a[l]);
	}

	dp[l][r] = temp;
	return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    rep(i , 1 , n) rep(j , 1 , n) dp[i][j] = -1;

    cout << DP(1 , 1 , n) << endl;

    return 0;
}
