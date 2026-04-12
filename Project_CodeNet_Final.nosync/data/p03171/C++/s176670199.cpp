#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;


ll arr[3000], memo[3000][3000], bl[3000][3000], maxi, n, ans, dif, sum;

ll dp(ll x, ll y){
	ll depan = 0;
	ll belakang = 0;
	if (x == y){
		return arr[x];
	}
	if (x > y){
		return 0;
	}
	if (bl[x][y] == 1){
		return memo[x][y];
	}
	bl[x][y] = 1;
	depan = arr[x] + min(dp(x+2, y), dp(x+1, y-1));
	belakang = arr[y] + min(dp(x, y - 2), dp(x+1, y-1));
	memo[x][y] = max(depan, belakang);
	return memo[x][y];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

	cin >> n;
	for (ll i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];
	} 
	ans = dp(1, n);
	dif = sum - ans;
	dif = ans - dif;
	cout << dif << '\n';
}
  