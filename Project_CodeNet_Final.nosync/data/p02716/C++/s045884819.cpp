#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll dp[1000000+10][6];
ll a[1000000+10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i];
	}
	dp[1][0]=a[1];
	dp[1][1]=a[1];
	dp[2][0]=a[2];
	dp[2][1]=a[2];
	if(n%2==0){
		rep(i,3,n+1){
			if(i%2==0) dp[i][1]=max(dp[i-3][0],dp[i-2][1]);
			else dp[i][1]=dp[i-2][1];
			dp[i][0]=dp[i-2][0];
			dp[i][0]+=a[i];
			dp[i][1]+=a[i];
		}
		cout<<max(dp[n-1][0],max(dp[n][0],dp[n][1]));
	}
	else{
		rep(i,3,n+1){
			dp[i][4]=max(dp[i-3][0],dp[i-2][4]);
			if(i>=5&&i%2==1) dp[i][3]=dp[i-4][0];
			if(i%2==0) dp[i][1]=max(dp[i-3][0],dp[i-2][1]);
			else dp[i][1]=dp[i-2][1];
			dp[i][0]=dp[i-2][0];
			dp[i][3]=max(dp[i][3],dp[i-2][3]);
			if(i%2==1) dp[i][2]=dp[i-3][1];
			dp[i][2]=max(dp[i][2],dp[i-2][2]);
			dp[i][0]+=a[i];
			dp[i][1]+=a[i];
			dp[i][2]+=a[i];
			dp[i][3]+=a[i];
			dp[i][4]+=a[i];
		}
		ll t1=max(max(max(dp[n][0],dp[n][1]),max(dp[n][2],dp[n][3])),dp[n][4]);
		ll t2=max(max(max(dp[n-1][0],dp[n-1][1]),max(dp[n-1][0],dp[n-1][0])),dp[n-1][4]);
		cout<<max(dp[n-3][1],max(dp[n-2][0],max(t1,t2)));
	}
	return 0;
}