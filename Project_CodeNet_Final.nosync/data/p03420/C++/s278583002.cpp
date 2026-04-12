#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
#define MOD (1000000007ll)
#define l_ength size

int main(void){
	ll n,k,i,ans=0ll;
	cin >> n >> k;
	if(k){
		for(i=(k+1); i<=n; ++i){
			ans += (n/i)*(i-k);
			ans += max(0ll,((n%i)-k+1));
		}
	}else{
		ans = n * n;
	}
	cout << ans << endl;
	return 0;
}
