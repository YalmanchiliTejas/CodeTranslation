#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <map>

using namespace std;

void show(vector<int> &v) {
	for (auto x: v) {
		fprintf(stderr, "%5d ", x);
	}
	fprintf(stderr, "\n");
}

int main() {
	long long n;
	int x, m;
	cin >> n >> x >> m;

	map<int, int> nums;

	vector<int> a = {x};
	vector<int> v_st, v_loop;

	int loop_st = -1, loop_size = -1;
	for (int i = 1; i < n; i++) {
		int x = 1LL * a[i-1] * a[i-1] % m;
		auto it = nums.find(x);
		if (it != nums.end()) {
			loop_st = it->second;
			loop_size = a.size() - loop_st;

			v_st = a;
			v_st.erase(v_st.begin() + loop_st, v_st.end());

			v_loop = a;
			v_loop.erase(v_loop.begin(), v_loop.begin() + loop_st);
			break;
		}

		nums[x] = i;
		a.emplace_back(x);
	}
	if (v_loop.empty()) {
		v_st = a;
	}

// fprintf(stderr, "loop_st %d, loop_size %d, a.size %lu\n", loop_st, loop_size, a.size());
// show(v_st);
// show(v_loop);
// fprintf(stderr, "v_st   %lu\n", v_st.size());
// fprintf(stderr, "v_loop %lu\n", v_loop.size());


	long long rest = n - v_st.size();
	long long sum_st = 0, sum_loop = 0, sum_ed = 0;

	for (auto x: v_st) {
		sum_st += x;
	}

	if (!v_loop.empty()) {
		for (auto x: v_loop) {
			sum_loop += x;
		}
		sum_loop *= rest / v_loop.size();

		for (int i = 0; i < rest % v_loop.size(); i++) {
			sum_ed += v_loop[i];
		}
	}

	long long ans = sum_st + sum_loop + sum_ed;
	cout << ans << endl;
	return 0;
}
