#include<bits/stdc++.h>

using lint = long long int;
using pii = std::pair<int, int>;
using pll = std::pair<lint, lint>;
using node = std::pair<lint, pll>;

using std::vector;
using std::min;
using std::max;
using data_type = int;

class Union_Find {
public:
	vector<data_type> ve;
	vector<data_type> level;

	void init(data_type size); // vector 초기화
	data_type find(data_type num); // 값을 찾아주는 함수
	void merge(data_type num1, data_type num2); // 그룹 결합
};
void Union_Find::init(data_type size) {
	ve.clear();
	level.clear();

	for (data_type i = 0; i <= size; i++) {
		ve.push_back(i);
		level.push_back(1);
	}
}
data_type Union_Find::find(data_type num) {
	int temp = num;
	while (ve[num] != num) {
		num = ve[num];
	}
	ve[temp] = num;
	return num;
}
void Union_Find::merge(data_type num1, data_type num2) {
	num1 = find(num1);
	num2 = find(num2);
	if (num1 == num2) {
		return;
	}

	if (level[num1] >= level[num2]) {
		ve[num2] = num1;
		level[num1] = max(level[num1], 1 + level[num2]);
	}
	else {
		ve[num1] = num2;
		level[num2] = max(level[num2], 1 + level[num1]);
	}
}

vector<pll> ve[2];
vector<node> real[2];

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		lint t1, t2;
		scanf("%lld %lld", &t1, &t2);
		ve[0].push_back(pll(t1, i));
		ve[1].push_back(pll(t2, i));
	}
	sort(ve[0].begin(), ve[0].end());
	sort(ve[1].begin(), ve[1].end());
	for (int i = 0; i < N - 1; i++) {
		real[0].push_back(node(ve[0][i + 1].first - ve[0][i].first, pll(ve[0][i].second, ve[0][i + 1].second)));
		real[1].push_back(node(ve[1][i + 1].first - ve[1][i].first, pll(ve[1][i].second, ve[1][i + 1].second)));
	}
	sort(real[0].begin(), real[0].end());
	sort(real[1].begin(), real[1].end());

	Union_Find temp;
	temp.init(N);

	int ind1 = 0, ind2 = 0, cou = 1;
	lint ans = 0;
	while (cou < N) {
		int cur1, cur2, val;
		if (real[0][ind1].first < real[1][ind2].first) {
			cur1 = real[0][ind1].second.first;
			cur2 = real[0][ind1].second.second;
			val = real[0][ind1].first;
			ind1++;
		}
		else {
			cur1 = real[1][ind2].second.first;
			cur2 = real[1][ind2].second.second;
			val = real[1][ind2].first;
			ind2++;
		}
		if (temp.find(cur1) != temp.find(cur2)) {
			cou++;
			temp.merge(cur1, cur2);
			ans += val;
		}
	}

	printf("%lld", ans);

	return 0;
}