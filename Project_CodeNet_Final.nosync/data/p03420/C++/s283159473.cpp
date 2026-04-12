#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	long long int n,k;
	cin >> n >> k;
	if(k==0){
		cout << n*n << endl;
		return 0;
	}
	
	long long int ans=0;
	for(int i=1; i<=n; i++){
		long long int rest = n+1;
		ans += rest/i*max(i-k, 0LL);
		rest %= i;
		if(rest > k) ans += rest-k;
	}
	cout << ans << endl;
	return 0;
}