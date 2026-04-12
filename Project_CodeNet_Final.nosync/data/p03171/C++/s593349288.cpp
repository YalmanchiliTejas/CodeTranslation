#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ST first
#define ND second
#define ll long long
#define ld long double
using namespace std;
using namespace __gnu_pbds;

// replace int with pair if multiset needed
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set secik;

const int INF = 1e9 + 9;
const int MOD = 1e9 + 7;
const long long LINF = (ll)1e18 + 3;

// secik.insert({x, t++});
// secik.erase(secik.lower_bound({x,-1}));
// *secik.find_by_order(x)).first << "\n";
// secik.order_of_key(x)

//random_device device;
//mt19937 gener(device());
//uniform_int_distribution<int> gen(0,n-1);
//gen(gener); // generate random number

const int SIZE = 4e3 + 5;

ll dp[SIZE][SIZE];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<ll> tab(n);
	for(int i = 0; i < n; i++) cin >> tab[i];

	for(int i = n - 1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(j-i == 0) dp[i][j] = tab[i];
			else dp[i][j] = max(tab[i] - dp[i+1][j],tab[j] - dp[i][j-1]);
		}
	}
	
	cout << dp[0][n-1];





}