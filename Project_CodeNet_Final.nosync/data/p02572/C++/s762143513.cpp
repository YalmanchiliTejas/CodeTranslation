/*
Created on Thu Aug 27 21:32:39 2020

@author: roastedcoder

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9+7;
const int INF = INT_MAX;
#define endl "\n"
#define append push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
//__________________________________________________________________


int main() {
	roastedcoder
	ll n; cin>>n;
	ll a[n], dp[n] = {0};
	cin>>a[0];
	dp[0] = a[0];
	for(int i = 1; i<n; i++) {
		cin>>a[i];
		dp[i] = dp[i-1]+a[i];
	}
	ll res = 0;
	for(int i = 0; i<n; i++) {
		res += (((dp[n-1] - dp[i])%mod)*a[i])%mod;
	}
	cout<<res%mod<<endl;
}

//__________________________________________________________________
/*
Sample Input:


Sample Output:


*/