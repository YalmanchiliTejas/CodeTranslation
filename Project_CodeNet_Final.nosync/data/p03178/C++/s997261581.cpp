#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
#define int ll
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define pii pair<int,int>
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define initialize(arr,elem) memset(arr,elem,sizeof(arr))
#define sz size
const int MOD = 1e9+7;
const int MAX_SZ = 2e5+9;
const int INF = 1e18+9;

// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n,d;
string s;
int dp[10003][101][2];


void rand_shuff(vi &arr){
	random_device rd;
	mt19937 g(rd());
	shuffle(all(arr),g);
}
int solve(int k, int su, int check){
	if (k<=0) return 0;
	if (dp[k][su][check] != -1) return dp[k][su][check];
	int cur = s[n-k] - '0';
	if (k==1){
		if (check){
			int res = 0;
			For(i,0,10){
				if (i%d == su) res++;
			}
			return dp[k][su][check] = res%MOD;
		}
		else{
			int res = 0;
			For(i,0,cur+1){
				if (i%d == su) res++;
			}
			return dp[k][su][check] = res%MOD;
		}
	}

	if (check){
		int res = 0;
		For(i,0,10){
			res += solve(k-1,(su-(i%d)+d)%d,check);
			res %= MOD;
		}
		return dp[k][su][check] = res%MOD;
	}
	else{
		int res = 0;
		//cout<<"in\n";
		res += solve(k-1,(su-cur+d)%d,0);
		res%= MOD;
		For(i,0,cur){
			res += solve(k-1,(su-i+d)%d,1);
			res %= MOD;
		}
		return dp[k][su][check] = res%MOD;
	}


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>s;
	cin>>d;
	n = s.sz();

	initialize(dp,-1);

	cout<<(solve(n,0,0)-1+MOD)%MOD<<endl;

	return 0;
}
