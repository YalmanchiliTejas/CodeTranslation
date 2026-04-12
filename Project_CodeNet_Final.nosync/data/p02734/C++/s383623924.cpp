/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 998244353
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 3005
#define fi(a, b, c, d) for(int a = b; i < c; i += d)
#define fl(a, b, c, d) for(ll a = b; i < c; i += d)
#define quit exit(0)

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
ll cache[MAX_INT][MAX_INT];
vector<ll> V;

ll modSum(ll A, ll B) {
	return(A + B) % MOD;
}

ll rec(ll ind, ll sum) {
	// cout << ind << " " << sum <<" \n";
	if(sum == 0) {
		return N - ind + 1;	
	}
	if(sum < 0) {
		return 0;
	}
	if(ind >= N) {
		return 0;
	}
	ll &ans = cache[ind][sum];
	if(ans != -1) {
		return ans;
	}
	ans = modSum(rec(ind + 1, sum), rec(ind + 1, sum - arr[ind])); 
	return ans;
}	


int main() {
	scanf("%lld %lld", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}	
	ll finalAns = 0;
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < N; i++) {
		finalAns = modSum(finalAns, rec(i, M));
	}
	printf("%lld\n", finalAns);
	return 0;
}
/*
	Powered by Buggy Plugin
*/


