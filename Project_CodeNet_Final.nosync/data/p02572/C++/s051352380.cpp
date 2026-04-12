#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#include <queue>
#include<map>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define PI 3.14159265358979323846264338327950


int main() {
	ll N, mod = 1000000007, x = 0, num = 0, ans = 0;

	cin >> N;
	vector<ll> a(N);
	rep(i, N)cin >> a[i];

	rep(i, N){
		num += a[i];
	}

	rep(i, N-1){
		num = num - a[i];
		x += (num%mod)*a[i] % mod;
	}
	x = x%mod;

	cout << x << endl;
	return 0;
}