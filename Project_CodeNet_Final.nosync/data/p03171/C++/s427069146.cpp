#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define trace(x)     cerr<<#x<<":"<<x<<endl;
#define trace2(x,y) cerr<<#x<<":"<<x<<"|"<<#y<<":"<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<":"<<x<<"|"<<#y<<":"<<y<<"|"<<#z<<":"<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
const int mx =3007;
vl a(mx);
vector<vl > dp(mx, vl(mx,-1));
ll solve(int i, int j){
	if(i>j)return 0;
	if(dp[i][j]==-1){
		ll aa = a[i] + min(solve(i+1,j-1), solve(i+2,j));
		ll bb = a[j] + min(solve(i+1,j-1), solve(i,j-2));
		dp[i][j] = max(aa,bb);
		// trace3(i,j,dp[i][j])
	}
	return dp[i][j];
}
int main(){
	fast_io;
	int n;
	cin>>n;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	ll f = solve(0,n-1);
	// trace(f)
	ll s = sum - f;
	cout<<f-s;
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}