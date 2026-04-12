#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,x,ans,mod=1000000007;
	cin >> a >> b >> x;
	ans=0;
	if(x>=a){
		ans+=(((1+(x-a)/(a-b)))%mod)*(a%mod);
		ans%=mod;
		x-=((1+(x-a)/(a-b))%mod)*((a-b)%mod);
	}

	ans=(ans+x)%mod;
	cout << ans << endl;
	return 0;
}
