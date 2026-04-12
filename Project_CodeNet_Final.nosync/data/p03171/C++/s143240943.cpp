#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define Test ll t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define loopS(i,a,b,step) for(ll i=a;i<b;i+=step)
#define loopRS(i,a,b,step) for(ll i=a;i>=b;i-=step)
#define ull unsigned long long int
#define pll pair<ll,ll>
#define puu pair<ull, ull>
#define V vector
#define M map
#define UM unordered_map
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define S3(a,b,c) cin >> a >> b >> c
#define S2(a,b) cin >> a >> b
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

void input(ll n, ll arr[]) {
	rep(i, 0, n)cin >> arr[i];
}
ll dp[3001][3001];
ll maximumX(ll arr[], ll st, ll end, ll n) {
	if (st > end)return 0;
	if (dp[st][end] != -1)return dp[st][end];
	// arr ki indexing 1 se hoti tu n karte.
	ll pos = (n - 1) - (end - st);
	// debug(pos);
	if (!(pos & 1)) {
		return dp[st][end] = max(maximumX(arr, st + 1, end, n) + arr[st], maximumX(arr, st, end - 1, n) + arr[end]);
		// even hai tu tiro try kar raha max karne ki.
	}
	return dp[st][end] = min(maximumX(arr, st + 1, end, n) - arr[st], maximumX(arr, st, end - 1, n) - arr[end]);
	// dusra try kar raha hai min aaye minus isliye kiya kyunki ye use ho gaya koi ek hi aayega ans mai.
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout.tie(NULL);
	ll n; cin >> n; ll arr[n];
	input(n, arr);
	ll sum = 0;
	// rep(i, 0, n)sum += arr[i];
	// debug(sum);
	rep(i, 0, 3001) {
		rep(j, 0, 3001)dp[i][j] = -1;
	}
	rep(i, 0, n)sum += arr[i];
	cout << maximumX(arr, 0, n - 1, n);
}
