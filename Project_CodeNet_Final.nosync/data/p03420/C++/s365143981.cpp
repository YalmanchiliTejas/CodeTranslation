#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin>>n>>k;
	long long ans = 0;
	if(k == 0){	cout<<(long long)n*n; return 0;}
	for(int i = k+1;i<=n;i++){
		int maxQuotient = n/i;
		ans += maxQuotient*(i-k);
		if(maxQuotient*i+k<=n)	ans += n-maxQuotient*i-k+1;
	}
	cout<<ans;
	return 0;
}