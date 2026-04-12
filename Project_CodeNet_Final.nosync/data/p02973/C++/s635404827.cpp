#include <bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#include "string"

int lis(vector<int>&a){
	vector<int>dp;
	for(int &i:a){
		int tt = upper_bound(dp.begin(),dp.end(),i) - dp.begin();
		if(tt == dp.size())
			dp.push_back(i);
		else
			dp[tt] = i;
	}
	return dp.size();
}

int32_t main(){
	boost;
	int n;
	cin >> n;
	vector<int>a(n);
	for(int &i:a)
		cin>>i;
	reverse(a.begin(),a.end());
	int ans = lis(a);
	cout<<ans<<endl;
}

