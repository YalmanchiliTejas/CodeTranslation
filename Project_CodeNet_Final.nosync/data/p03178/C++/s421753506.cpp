#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;
 
#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
 
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[100010][110][2];
 
int main(){
	string K; cin >> K;
	int D; cin >> D;
	int N = K.size();
	dp[0][0][0] = 1;
	rep(i,N)rep(j,D)rep(k,2){
		int d = K[i]-'0';
		rep(l,10){
			if(l < d){
				dp[i+1][(j+l)%D][1] += dp[i][j][k];
				dp[i+1][(j+l)%D][1] %= MOD;
			}
			else if(l == d){
				dp[i+1][(j+l)%D][k] += dp[i][j][k];
				dp[i+1][(j+l)%D][k] %= MOD;
			}
			else{
				if(k == 1){
					dp[i+1][(j+l)%D][k] += dp[i][j][k];
					dp[i+1][(j+l)%D][k] %= MOD;
				}
			}
		}
	}
	ll ans = (dp[N][0][0] + dp[N][0][1]-1) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << endl;
}
