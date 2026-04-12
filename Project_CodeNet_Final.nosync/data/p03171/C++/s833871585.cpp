#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ff first
#define ss second
 
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
 
const int inf = 2e18;
const int ninf = -2e18-5;
const int mod = 1e9 + 7;
 
int dp1[5010][5010];
int dp2[5010][5010];
vector<int> arr;
vector<int> pre;
 
int solve(int i, int j, int p){
	// cout<<i<<" "<<j<<" "<<p<<endl;
	if(p){
		if(i==j) {
			dp2[i][j] = arr[i];
			// cout<<"yo "<<dp2[i][j]<<endl;
			return dp2[i][j];
		}
		if(dp1[i+1][j]==ninf) solve(i+1, j, 0);
		if(dp1[i][j-1]==ninf) solve(i, j-1, 0);
		dp2[i][j] = max(arr[i]+pre[j+1]-pre[i+1]-dp1[i+1][j], pre[j]-pre[i]-dp1[i][j-1]+arr[j]);
		
		return dp2[i][j];		
	}
	else{
		if(i==j) {
			dp1[i][j] = arr[i];
			// cout<<"yo "<<dp1[i][j]<<endl;
			return dp1[i][j];
		}
		if(dp2[i+1][j]==ninf) solve(i+1, j, 1);
		if(dp2[i][j-1]==ninf) solve(i, j-1, 1);
		dp1[i][j] = max(arr[i]+pre[j+1]-pre[i+1]-dp2[i+1][j], pre[j]-pre[i]-dp2[i][j-1]+arr[j]);
		
		return dp1[i][j];		
	}
}
signed main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif
 
	int n; cin>>n;
	int cur = 0;
	pre.pb(cur);
	for(int i=0; i<n; i++){
		int x; cin>>x;
		cur+=x;
		pre.pb(cur);
		arr.pb(x);
	}
 
	for(int i=0; i<5010; i++){
		for(int j=0; j<5010; j++){
			dp1[i][j] = ninf;
			dp2[i][j] = ninf;
		}
	}
 
	cout<<2*solve(0, n-1, 0)-cur<<endl;

	return 0;
}