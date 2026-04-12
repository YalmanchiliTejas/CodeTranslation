#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define nl cout<<"\n"
#define pb push_back
#define se second
#define fi first
#define int long long 
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define For(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,n) for(int i=a;i<n;i++)
#define pie =3.14159265358979323846264338327950;
const int mod= 1e9+7;

int n;
int ar[3005];
int dp[3005][3005];

int f(int start, int end){
	if(start>end){
		return 0;
	}
	if(start==end){
		return ar[start];
	}
	if(dp[start][end]!=-1) return dp[start][end];
	int ans= max({ar[start]+min(f(start+2,end),f(start+1,end-1)), ar[end]+min(f(start+1,end-1), f(start,end-2))});
	//cout<<start<<" "<<end<<" "<<ans<<endl;
	dp[start][end]=ans;
	return ans;
}

void solve(){
	fio;
	cin>>n;
	int sum=0;
	For(i,n){
		cin>>ar[i];
		sum+=ar[i];
	}
	memset(dp,-1,sizeof(dp));
	int k= f(0,n-1);
	//cout<<k<<endl;
	cout<<2*k-sum<<endl;
}

int32_t main(){
	fio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){ 
		//cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}
