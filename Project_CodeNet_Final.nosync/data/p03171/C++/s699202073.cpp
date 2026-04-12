#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3005][3005];

// This problem is same as optimal strategy for game.

ll solve(ll a[], int start, int end){
	if(start > end)
		return 0;
		
	if(start==end)
		return a[start];
	
	if(start+1 == end) {
		return max(a[start], a[end]);		
	}
	
	if(dp[start][end] != -1)
		return dp[start][end];
	
	ll ans=0;	
	
	// choose from start.
	ll choose_start = a[start] + min( solve(a, start+2, end), solve(a, start+1, end-1) );
	
	// choose from end
	ll choose_end = a[end] + min( solve(a, start+1, end-1) , solve(a, start, end-2) );
	
	// take max dicision which is beneficial
	ans = max(choose_start, choose_end);
	
	return dp[start][end] = ans;
}

void iterative(ll a[], int n, ll tot){
	// our dp state
	// dp[L][R][P] -> (L...R) of Pth player
	
	// here we only focus on first player score we get second automatic.
	// so choose our dp accordingly.
	
	ll dp[n+1][n+1][3]={};
	
	// base case if player 1 turn and both same means we best get a[i]
	// if L==R but second player turn so he choose that and first get nothing so = 0.
	
	for(int i=0; i<n; i++){
		dp[i][i][1]=a[i];
		dp[i][i][2]=0;
	}
	
	// we do for L==R now slowly to move both ooposite side so (R-L) increasing i.e=len
	
	for(int len=1; len<n; len++){
		for(int L=0; L+len < n; L++){
			int R = L+len;
			
			// if player 1 choose first now he get second L+1....R
			// same for last pick
			dp[L][R][1]=max( a[L] + dp[L+1][R][2], a[R] + dp[L][R-1][2] );
			
			// player 2 turn so we not add a[L] or a[R] because we only focus on player 1.
			dp[L][R][2]=min( dp[L+1][R][1], dp[L][R-1][1] );
			
		}
	}
	
	ll x = dp[0][n-1][1];
	ll y = tot - x;
	
	cout << x-y << "\n";
	
}

void solve(){
	int n;
	cin >> n;
	
	ll a[n]={};
	long long int tot=0;
	
	for(int i=0; i<n; i++) {
		cin >> a[i];
		tot+=a[i];
	}
	
	// iterative version.
	iterative(a, n, tot);
	return;
	
	memset(dp, -1, sizeof dp);
	
	// [X-Y] maximize means max X, minimize means min X
	
	// play optimally and try to make sum as max as posible.
	// we get val of X.
	// then y = tot-x;
	// ans=x-y.
	
	ll x = solve(a, 0, n-1);
	ll y = tot-x;
	
	cout << x-y << "\n";
}

int main(){
	solve();
}
