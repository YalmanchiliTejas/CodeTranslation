#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	long long ans = 0;
	cin >> n >> k;
	if (k == 0) {
		cout << n*n << endl;
		return 0;
	}

	for (int b = k + 1; b <= n; b++) {
		ans += n / b * (b-k);
		int r = n - n / b*b;
		if (r) {
			if (r >= k) ans += r - k + 1;
		}
	}
	cout <<ans<< endl;


	return 0;
}