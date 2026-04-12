#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define E 2.71828182845905
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define debug(x) cout<<#x<<" is "<<x<<endl;
#define PI 3.14159265
#define mem(x) memset(x,0,sizeof(x));
using namespace std;

void sol() {
	int n;
	cin>>n;
	ll arr[n+1];
	rep(i,1,n+1)
	cin>>arr[i];
	ll psum[n+1];
	mem(psum);
	rep(i,1,n+1)
		psum[i]=psum[i-1]+arr[i];
	ll dp[n+1][n+1];
	mem(dp);
	rep(i,1,n+1){
		dp[i][i]=arr[i];
	}
	rep(l,2,n+1){
		rep(i,1,n+1){
			int j=i+l-1;
			if(j>n)
				break;
			if(dp[i+1][j]<dp[i][j-1]){
				dp[i][j]=psum[j]-psum[i-1]-dp[i+1][j];
			}
			else {
				dp[i][j]=psum[j]-psum[i-1]-dp[i][j-1];
			}
		}
	}
	cout<<2*dp[1][n]-psum[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
 	//cin>>t;
 	while(t--){	
	sol();
 	}
}