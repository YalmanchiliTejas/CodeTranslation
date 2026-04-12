#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll inv2=5e8+4;
int n;

void solve(){
	scanf("%d",&n);
	ll sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		sum1=(sum1+x)%MOD;
		sum2=(sum2+x*x%MOD)%MOD;
	}
	ll res=(sum1*sum1%MOD-sum2+MOD)%MOD*inv2%MOD;
	printf("%lld\n",res);
}
int main(){
	solve();
	return 0;
}