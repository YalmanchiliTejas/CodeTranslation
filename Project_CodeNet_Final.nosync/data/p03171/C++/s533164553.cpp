#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define FF first
#define SS second
#define pii pair<int,int>
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(x) (int)x.size()
#define mp make_pair
#define Mod 1000000007
typedef long long int ll;
// g++ -DLOCAL -std=c++17 -Wshadow -Wall  "codeforces.c++" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

// dp[i] -> store result whether present player playing the tuen is able to win or not if i stones left

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// #endif

	int n, l, r;

	cin >> n;
	vector<int> seq(n);

	for(int &x : seq)
		cin >> x;
	// cout<<seq.size()<<"\n";
	// for(int x : seq)
	// 	cout<<x<<" ";

	vector<vector<ll>> dp(n, vector<ll>(n));

	for(l = n-1; l >= 0; l--)
		for(r = l; r < n; r++){
			// cout<<l<<" "<<r<<"\n";
			if(l == r)
				dp[l][r] = seq[l];
			else
				dp[l][r] = max(seq[l] - dp[l+1][r], seq[r] - dp[l][r-1]);
		}

	cout<<dp[0][n-1]<<"\n";


}	
