#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define VAL 100000
#define ll long long
#define INF 10000000000000000LL
#define pll pair<long long , long long>
const int MAX=1e6+10;
const int MOD=1e9+7;
const int TOT_PRIMES=19;
const int MAX_A=70;
using namespace std;
vector<int>adj[MAX];
int coun(int x){
	return __builtin_popcount(x);
}
ll dp[3005][3005];
int main() 
{ 
	//ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);	
//	#ifndef ONLINE_JUDGE
	//freopen("inp.txt" ,"r", stdin );
//	freopen("out.txt", "w", stdout);
//	#endif
	int n;
	cin>>n;
	ll arr[n+1];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(l==r)
				dp[l][r]=arr[l];
			else
				dp[l][r]=max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1];
}