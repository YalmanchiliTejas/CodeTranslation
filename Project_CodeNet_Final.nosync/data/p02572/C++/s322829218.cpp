#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	vector<int>num(n);
	
	long long int mod = 1000000007;
	
	long long int sum = 0;
	for (int i = 0;i <n;i++ ){
		cin >> num[i];
		sum += num[i];
		sum %= mod;
	}
	
	long long int ans = 0;
	for (int i = 0; i < n;i++){
		sum -= num[i];
		
		if (sum < 0) sum += mod;
		ans += num[i]*sum;
		ans %= mod;
	}
	
	cout << ans;
	
	
	return 0;
}
		
