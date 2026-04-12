#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 200;

string s;
int n, k;

ll dp[maxn][5];

bool ok(){
	int cnt = 0;
	for(auto &c : s)
		if(c != '0')
			cnt++;
	return cnt == k;
}

ll solve(int pos, int cnt){
	if(pos == 0){
		if(cnt == 0)
			return 1;
		return 0;
	}
	
	if(cnt < 0)
		return 0;
	
	if(dp[pos][cnt] != -1)
		return dp[pos][cnt];
	
	ll ans = 0;
	
	for(int i = 0; i < 10; i++){
		int add = i != 0;
		if(cnt - add >= 0)
			ans += solve(pos - 1, cnt - add);
	}
	
	return dp[pos][cnt] = ans;
	
}

ll f(){
	ll ans = 0;
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		int top = s[i] - '0';
		
		for(int j = 0; j < top; j++){
			int add = j != 0;
			ans += solve(n - i - 1, k - cnt - add);
		}
		
		if(top != 0)
			cnt++;
	}
	
	if(ok())
		ans++;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> s >> k;
	n = (int)s.size();
	
	memset(dp, -1, sizeof(dp));
	ll ans = f();
	
	cout << ans << endl;

	return 0;
}
