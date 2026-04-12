#include <bits/stdc++.h>
#define IOS   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define pi 	  3.14159265358979323846
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size() 
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define mod   1000000007
#define qe	  998244353
#define MAXN  100005
#define mx    10000005
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define inv(i,a,b)  for(i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;
int main(){
//	#ifndef ONLINE_JUDGE
//    if (fopen("input.txt", "r"))
//    {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    }
//	#endif
	IOS;
	ll t,n,l,l1;
	ll i,j,m,mn,q,d,x,y,sum=0,r,p,k,c;
	string s,s1;
	cin>>n;
	ll a[n];
	rep(i,0,n)cin>>a[i];
	ll dp[n][n][2];
	rep(i,0,n)dp[i][i][0]=a[i],dp[i][i][1]=-a[i];
	rep(j,1,n){
		rep(i,0,n-j){
			dp[i][i+j][0]=max(dp[i][i+j-1][1]+a[i+j],dp[i+1][i+j][1]+a[i]);
			dp[i][i+j][1]=min(dp[i][i+j-1][0]-a[i+j],dp[i+1][i+j][0]-a[i]);
//			cout<<"("<<dp[i][i+j][0]<<", "<<dp[i][i+j][1]<<") ";
		}
//		cout<<endl;
	}
	cout<<dp[0][n-1][0];
}