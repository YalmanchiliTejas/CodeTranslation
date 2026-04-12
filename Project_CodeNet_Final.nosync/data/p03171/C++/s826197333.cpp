#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair <int,int> ii ;
typedef vector < ii > vii ;
typedef vector < vii > viii ;
#define rep(i,n)                   for( ll i = 0 ; i < n ; i++)
#define repu(i,a,b)                for(int i = a ; i <= b ; i++) 
#define repd(i,b,a)                for(int i = b ; i >= a ; i--)
#define pb push_back
#define db double 
#define fi first
#define se second
const ll mod =1000000007;

ll dp[3000][3000];
ll dp1[3000][3000];

ll calc(ll a[], int i, int j);

ll calc2(ll a[], int i, int j) {
	if(i==j) return -a[i];
	if(i>j) return 0;
	if(dp1[i][j]!=-1) return dp1[i][j];
	dp1[i][j]=min(calc(a,i+1,j)-a[i], calc(a,i,j-1)-a[j]);
	return dp1[i][j];
}

ll calc(ll a[], int i, int j) {
	if(i==j) return a[i];
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=max(a[i]+calc2(a,i+1,j), a[j]+calc2(a,i,j-1));
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n; cin>>n;
  	ll a[n];
  	rep(i,n) cin>>a[i];
  	memset(dp,-1, sizeof dp);
  	memset(dp1, -1, sizeof dp1);
  	cout<<calc(a,0,n-1);
}