#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
long long ni(long long ta, vector<long long> & v) {

}
long long rui(long long n, long long k, long long p) {
	if (k == 0) {
		return 1;
	}
	else {
		long long a = rui(n, k / 2, p);
		if (k % 2 == 0) {
			return (a*a) % p;
		}
		return (((a*a) % p)*n) % p;
	}
}
int main(){
	int n; cin >> n;
	int ans = 101;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sum += a;
		ans = min(ans, sum / (i + 1));
	}
	cout << ans << endl;
}
