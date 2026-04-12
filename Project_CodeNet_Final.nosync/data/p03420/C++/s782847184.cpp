#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()
#define ll long long
const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

int main(void){
	ll N,K;
	cin >> N >> K;
	long long ans = 0;
	for(ll b=1;b<=N;b++){
		ans += max((ll)0,b-K)*(N/b) + max((ll)0,N%b-K+1);
	}
	if(K==0)ans = N*N;
	cout << ans << endl;
}