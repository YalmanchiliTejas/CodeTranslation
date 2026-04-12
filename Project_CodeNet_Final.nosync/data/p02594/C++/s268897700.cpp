#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>
using Graph = vector<vector<int>>;
const double PI = 3.14159265358979323846;



long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


//約数をベクトル形式で返す
vector<int> vect_yakusuu(int n) {
	vector<int> ret;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			if (i*i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return ret;
}

int popcount(int A) {
	int count = 0;
	while (1) {
		if (A == 0) {
			break;
		}
		if (A % 2 == 1) {
			count++;
		}
		A = A / 2;
	}
	return count;
}

int main() {

	int N;
	int X;
	string ans;

	cin >> N;

	ans = "No";

	if (N >= 30) {
		ans = "Yes";
	}


	cout <<ans <<endl;

	cin >> N;

	return 0;


}