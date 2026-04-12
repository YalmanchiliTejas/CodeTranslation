#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
#define ALL(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 998244353;

int main(){
	int N, S; cin >> N >> S;
	int A[N];
	rep(i, N) cin >> A[i];
	ll dp[N][S+1], sum[N][S+1];
	ll ans = 0;
	rep(i, N)rep(j, S+1){
		if(i==0){
			if(j == A[i]) dp[i][j] = 1;
			else dp[i][j] = 0;
			sum[i][j] = dp[i][j];
		}else{
			if(j < A[i]) dp[i][j] = 0;
			else if(j == A[i]) dp[i][j] = i+1;
			else dp[i][j] = sum[i-1][j - A[i]];
			sum[i][j] = (sum[i-1][j] + dp[i][j]) % mod;
		}
	}
	rep(i, N){
		ans = (ans + (N-i) * dp[i][S] % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}
