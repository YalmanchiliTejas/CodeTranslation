#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	vi a(n);
	rep(i,0,n)cin>>a[i];
	vector<vector<ll>>dp(n,vector<ll>(n));
	for (int i=n-1;i>=0;i--){
		for (int j=i;j<n;j++){
			if (i==j)dp[i][j]=a[i];
			else{
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}