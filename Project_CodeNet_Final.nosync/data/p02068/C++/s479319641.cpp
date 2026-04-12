#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;


bool nprime[10044] = { };
int64_t A[10000];
std::set<int64_t> base;
std::vector<int64_t> prime;

int main()
{
	nprime[0] = nprime[1] = true;
	for (int i = 2; i <= 10000; i++)
	{
		if (!nprime[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				nprime[j] = true;
			}
		}
	}
	for (int i = 2; i <= 10000; i++) {
		if (!nprime[i]) {
			prime.push_back(i);
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		auto tmp = A[i];
		for (auto& v : prime) {
			if (tmp % v == 0) {
				base.insert(v);
				tmp /= v;
			}
		}
		if (tmp > 1) {
			base.insert(tmp);
		}
	}

	int64_t res = 0;
	for (auto& k : base)
	{
		int64_t tmp = 0;
		if(k > 1) for (int j = 0; j < N; j++) {
			if (A[j] % k == 0) {
				tmp += A[j];
			}
		}
		res = std::max(res, tmp);
	}
	cout << res << endl;
}
