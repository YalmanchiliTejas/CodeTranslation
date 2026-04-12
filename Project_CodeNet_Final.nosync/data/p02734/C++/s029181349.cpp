#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
typedef long long ll;
typedef long double ld;
using namespace std;

int A[3010];
ll mod=998244353, dp[3010][3010]={};

int main() {
	int N, S;
	cin >> N >> S;
	for(int i=0; i<N; ++i) cin >> A[i];
	for(int i=0; i<=S; ++i) dp[0][i]=0;
	ll ans=0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<=S; ++j){
			if(j<S) dp[i+1][j]=dp[i][j];
			if(j==A[i]) (dp[i+1][j] += i+1) %= mod;
			if(j>A[i]) (dp[i+1][j] += dp[i][j-A[i]]) %= mod;
		}
		(ans += (dp[i+1][S]*(N-i))%mod) %= mod;
	}
	cout << ans << endl;
	return 0;
}