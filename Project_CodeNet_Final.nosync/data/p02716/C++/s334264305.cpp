#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 n, a[202020];
i64 dp[202020][3];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i <= n+1; i++) for(int j = 0; j < 3; j++) dp[i][j] = -LINF;
	int k = 1+n%2;
	i64 ans = -LINF;
	queue<pair<P, i64>> q;
	q.push({{0,k},0});
	while(!q.empty()){
		pair<P,i64> p = q.front(); q.pop();
		i64 pos = p.first.first, c = p.first.second, sum = p.second;
		if(pos > n+1) continue;
		bool ok = 1;
		for(int i = c; i <= k; i++){
			if(dp[pos][i] >= sum) ok = 0;
		}
		if(!ok) continue;
		dp[pos][c] = sum;
		if(pos >= n){
			chmax(ans, sum);
			continue;
		}
		if(c) q.push({{pos+1,c-1},sum});
		q.push({{pos+2,c},sum+a[pos]});
	}
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
