#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
	ll n,k;
	cin >> n>>k;
	ll ans = 0;
	if (!k) {
		cout << n*n << endl;
	}
	else {
		FOR(b,k+1,n+1){
			//bを固定
			ans += (b-k)*(n/b);
			ll r = n%b - k + 1;
			if (r>0) ans += r;
		}
		cout << ans << endl;
	}
}
