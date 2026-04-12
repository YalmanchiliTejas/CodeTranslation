#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int ans=0,k;
string s;

int dp[110][4][2];

int solve(int pos,int n_k,bool less){
	if(n_k > k)
		return 0;
	if(pos==s.size())
		return n_k == k;
	if(dp[pos][n_k][less])
		return dp[pos][n_k][less];
	if(less){
		for(char c='0';c<='9';++c){
			dp[pos][n_k][less]+=solve(pos+1,n_k+(c!='0'),true);
		}
	}
	else{
		char great = s[pos];
		for(char c='0';c<great;++c){
			dp[pos][n_k][less]+=solve(pos+1,n_k+(c!='0'),true);
		}
		dp[pos][n_k][less]+=solve(pos+1,n_k+(great!='0'),false);
	}

	return dp[pos][n_k][less];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>k;
	cout<<solve(0,0,0)<<endl;
	return 0;
}