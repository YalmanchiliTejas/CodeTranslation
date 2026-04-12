#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cstring>
#include<unordered_map>
#include<set>
#define int long long
using namespace std;

signed main() {
	int MAX = 0;
	int a; cin >> a;
	unordered_map<int, int>U;
	U[0] = 1;
	int sum = 0;
	for (int b = 0; b < a; b++) {
		int c; scanf("%lld", &c);
		sum += c;
		if (U[sum] == 0) {
			U[sum] = b + 2;
		}
		else {
			MAX = max(MAX, b + 2 - U[sum]);
		}
	}
	cout << MAX << endl;
}