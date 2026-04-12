#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define INPUT(arr,n) for(ll i = 0;i<n;i++) cin>>arr[i];
#define PRINT(arr,n) for(ll i = 0;i<=n;i++) printf("%lld ",arr[i]);printf("\n");
#define MEM(var,val) memset(var,(val),sizeof(var))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define mp make_pair
#define pb push_back

const ll NMAX = 3000+7;
const ll MOD = 1000*1000*1000+7;
const ll INT_BITS = 32 ;
ll arr[NMAX];
ll dp[NMAX][NMAX][2];

inline ll add(ll a, ll b) {
  ll r = a + b;
  return (r >= MOD ? r - MOD : r);
}

inline ll sub(ll a, ll b) {
  ll r = a - b;
  return (r < 0 ? r + MOD : r);
}

inline ll mul(ll a, ll b) {
  ll r = a * b;
  return (r >= MOD ? r % MOD : r);
}

ll N;

ll solve(ll i, ll j,ll turn){
	if(i>j) return 0;
	if(dp[i][j][turn] != -1)return dp[i][j][turn];
	ll res;
	if(turn){
		res = max(solve(i+1,j,1-turn)+arr[i], solve(i,j-1,1-turn)+arr[j]);
	}
	else{
		res = min(solve(i+1,j,1-turn)-arr[i], solve(i,j-1,1-turn)-arr[j]);
	}
	return dp[i][j][turn]=res;
}
int main(int argc, char const *argv[])
{
	cin>>N;
	INPUT(arr,N);
	MEM(dp,-1);
	cout<<solve(0,N-1,1)<<endl;
	return 0;
}