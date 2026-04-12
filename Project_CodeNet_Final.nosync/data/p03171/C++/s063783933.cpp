#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define dd double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl '\n'

int n;
int a[3001];
vector<vector<int>> dp(3001,vector<int>(3001,-1));

int game(int i,int j){
	if(i>j)return 0;
	if(i==j){
		return a[i];
	}

	if(dp[i][j]!=-1) return dp[i][j];

	return dp[i][j] = max(a[i]-game(i+1,j),a[j]-game(i,j-1));
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;
	for0(i,n) cin>>a[i];

	cout<<game(0,n-1)<<endl;

	return 0;
}