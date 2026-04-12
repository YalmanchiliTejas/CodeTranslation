#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define M 1000000007

signed main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n], s=0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		s += arr[i];
	}

	int ans=0;
	for(int i=0; i<n; i++){
		ans += ((arr[i]%M)*((s-arr[i])%M))%M;
		ans%=M;
	}

	ans = (ans+M)%M;
	ans = (ans*(M+1)/2)%M;

	cout << ans;


	
	

	return 0;
}