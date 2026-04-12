#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> all(51), pate(51);

//{B, Lv.X-1, P, Lv.X-1, B}
ll dfs(int level, ll remain){
	if(level == 0){
		return 1;
	}
	
	ll ans = 0;
	
	//B
	if(remain >= 1){
		remain--;
	}
	//Lv.X-1
	if(remain >= 1){
		if(remain >= all[level - 1]){
			remain -= all[level - 1];
			ans += pate[level - 1];
		}else{
			ans += dfs(level - 1, remain);
			remain = 0;
		}
	}
	
	//P
	if(remain >= 1){
		remain--;
		ans++;
	}
	
	//Lv.X-1
	if(remain >= 1){
		if(remain >= all[level - 1]){
			remain -= all[level - 1];
			ans += pate[level - 1];
		}else{
			ans += dfs(level - 1, remain);
			remain = 0;
		}
	}
	
	//B
	if(remain >= 1){
		remain--;
	}
	
	return ans;
}

int main() {
	
	int n;
	ll x;
	cin >> n >> x;
	
	//dp
	all[0] = 1;
	pate[0] = 1;
	for(int i = 1; i < n; i++){
		all[i] = all[i - 1] * 2 + 3;
		pate[i] = pate[i - 1] * 2 + 1;
	}
	
	ll ans = dfs(n, x);
	cout << ans << endl;
	
	return 0;
}