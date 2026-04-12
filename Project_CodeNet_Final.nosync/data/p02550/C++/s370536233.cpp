//-----------------------
// author : xyqkoala
// time : 2020-09-20
//-----------------------

#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;

void solve();


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


void solve(){
	LL n,x,m;
	cin>>n>>x>>m;
	vector<LL> dp{0};
	vector<int> vis(m+1,0);
	LL s = x;
	int idx = 1;
	while(!vis[s]){
		vis[s] =idx++;
		dp.push_back(s+dp.back());
		s = (s*s)%m;
	}
	// for(auto item:dp) cout<<item<<endl;
	if(LL(dp.size())>n){
		cout<<dp[n]<<endl;
		return;
	}
	LL res = 0;
	res+=dp.back();
	int tn = dp.size()-1;
	n-=tn;
	int tcnt = tn+1-vis[s];
	res+=(n/tcnt) * (dp[tn]-dp[vis[s]-1]);
	n = n%tcnt;
	res+=dp[vis[s]+n-1]-dp[vis[s]-1];
	cout<<res<<endl;
}
