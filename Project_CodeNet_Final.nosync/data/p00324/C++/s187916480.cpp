#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	map<long long int, int>mp;
	vector<long long int>sums;
	long long int now = 0;
	for (int i = 0; i < N; ++i) {
		long long int a; cin >> a;
		now += a;
		sums.emplace_back(now);
	}
	int ans = 0;
	mp[0] = 0;
	for (int i = 0; i < N; ++i) {
		long long int sum = sums[i];
		if (mp.find(sum) != mp.end()) {
			ans = max(ans, i+1 - mp[sum]);
		}
		else mp[sum] = i+1;
	}
	cout << ans << endl;
	return 0;
}