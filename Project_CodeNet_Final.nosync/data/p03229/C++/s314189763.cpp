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



i64 n, a[101010];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	
	i64 ans = 0;
	if(n & 1){
		for(int i = 0; i < n; i++){
			ans += abs(a[i]-a[n/2]) * 2;
		}
		ans -= min(a[n/2+1]-a[n/2], a[n/2]-a[n/2-1]);
	}
	else{
		for(int i = 0; i < n; i++){
			ans += min(abs(a[i]-a[n/2]), abs(a[i]-a[n/2-1])) * 2;
		}
		ans += (a[n/2] - a[n/2-1]) * (n-1);
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
