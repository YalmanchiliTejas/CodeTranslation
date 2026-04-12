#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int>v(n);
	long long sum=0;
	int mod = 1000000007;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
		sum %= mod;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		sum -= v[i];
		if (0>sum)sum += mod;
		ans += sum *v[i];
		ans %= mod;
	}
	cout << ans;
	//system("pause");
	return 0;
}
