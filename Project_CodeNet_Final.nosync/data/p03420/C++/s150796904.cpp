#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,K;
	cin >> N >> K;
	ll ans = 0;
	if(K==0){
		cout << N*N << endl;
		return 0;
	}
	for(int b=K+1;b<=N;b++){
		ll l = K;
		ll r = b-1;
		ans += r-l+1;
		ll n = (N-r)/b;
		ans += n*(r-l+1);
		l = l +(n+1)*b;
		if(l<=N)ans += N-l+1;
	}
	cout << ans << endl;
}