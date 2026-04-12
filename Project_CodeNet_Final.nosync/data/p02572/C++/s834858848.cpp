#include <bits/stdc++.h>
#define mod (int)(2e9 + 14)
using namespace std;
int main(){
	long long sum = 0, minus = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum += x;
		minus += 1LL * x * x;
		sum %= mod;
		minus %= mod;
	}
	sum *= sum;
	sum %= mod;
	sum -= minus;
	sum += mod;
	cout << (sum / 2) % (mod / 2) << endl;
	return 0;
}