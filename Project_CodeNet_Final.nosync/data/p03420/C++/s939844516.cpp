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
	for(int b=K+1;b<=N;b++){
		ll p = N/b;
		ans += p*max(0LL,(ll)b-K);
		ans += max(0LL,N%(ll)b-K+1);
	}
	if(K==0)ans -=N;
	cout << ans << endl;
}