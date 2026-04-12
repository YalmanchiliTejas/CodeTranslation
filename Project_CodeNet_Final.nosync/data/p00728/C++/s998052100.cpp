#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;
list<long long int> Prime(int M) {
	list<long long int>P;
	P.push_back(2);
	P.push_back(3);
	for (int i = 5; i <= M; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	return P;
}


long long int N;
long long int ans;
long long int H, W;
long long int K;
list<long long int>ret;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	while (N) {
		vector<int>num(N);
		ans = 0;
		for (int i = 0; i < N; i++)cin >> num[i];
		sort(num.begin(), num.end());
		for (auto i : num)ans += i;
		ans -= num[0];
		ans -= num[N - 1];
		ret.push_back(ans / (N-2));
		cin >> N;
	}
	for (auto i : ret)cout << i << endl;
	return 0;
}