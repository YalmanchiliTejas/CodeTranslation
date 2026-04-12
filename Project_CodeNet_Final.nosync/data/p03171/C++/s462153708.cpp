#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define fo(n) for(int i = 0;i < int(n);i++)
#define foo(a,b) for(int i = int(a);i <= int(b);i++)
#define mk make_pair
#define pb push_back
#define MAXN 3000
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define fastio ios_base:: sync_with_stdio(false)

ll dp[MAXN][MAXN];
vector<ll> arr(MAXN);

ll sol(int l,int r){
	if(l > r) return 0;


	if(dp[l][r] != -1) return dp[l][r];

	ll lf = arr[l] + min(sol(l+2,r),sol(l+1,r-1));
	ll rf = arr[r] + min(sol(l+1,r-1),sol(l,r-2));

	dp[l][r] = max(lf,rf);
	return dp[l][r];
}


int main(){
	
	fastio;
	int n;
	cin >> n;

	fo(n) cin >> arr[i];

	memset(dp,-1,sizeof(dp));
	ll ans = sol(0,n-1);

	ll sum = 0;
	fo(n) sum += arr[i];

	cout << 2*ans - sum << endl; 

	return 0;
 }	