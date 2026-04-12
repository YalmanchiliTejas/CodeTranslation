#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = (int)1e9 + 7;
const int maxN = 2e5+5;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<lli> arr(n), pre(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		pre[i] = arr[i];
	}
	for(int i=n-2; i>=0; i--){
		pre[i] = (pre[i+1]+arr[i])%mod;
	}
	lli ans = 0;
	for(int i=0; i<n-1; i++){
		ans = (ans + (arr[i]*pre[i+1])%mod)%mod;
	}
	cout << ans ;
	
	//cout << "Hello World\n";
	return 0;
}