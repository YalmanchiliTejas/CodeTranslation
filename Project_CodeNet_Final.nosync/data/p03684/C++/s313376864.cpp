#include <iostream>
#include <algorithm>
#include <vector>

constexpr int MAX_N = (int)1e5, INF = (int)1e9;

using ll = long long int;

using P = std::pair<int, int>;

using Node = std::pair<int, P>;

int parent[MAX_N];
int rank[MAX_N];

int n;

void init() {

	for (int i = 0; i < n; ++i)
		parent[i] = i;
}

int find(int x) {

	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void unite(int x, int y) {

	x = find(x);

	y = find(y);

	if (rank[x] < rank[y])
		parent[x] = y;
	else {
		parent[y] = x;
		if (rank[x] == rank[y])
			++rank[x];
	}
}

bool same(int x, int y) {

	return find(x) == find(y);
}

P XX[MAX_N], YY[MAX_N];

std::vector<Node> vec;

int main() {

	std::cin >> n;

	init();

	for (int i = 0; i < n; ++i) {
		std::cin >> XX[i].first >> YY[i].first;
		XX[i].second = i;
		YY[i].second = i;
	}

	std::sort(XX, XX + n);

	std::sort(YY, YY + n);

	for (int i = 0; i < n - 1; ++i) {

		vec.emplace_back(XX[i + 1].first - XX[i].first, P(XX[i].second, XX[i + 1].second));

		vec.emplace_back(YY[i + 1].first - YY[i].first, P(YY[i].second, YY[i + 1].second));
	}

	std::sort(vec.begin(), vec.end());

	ll ans = 0;

	for (auto& x : vec) {

		if (!same(x.second.first, x.second.second)) {

			ans += x.first;

			unite(x.second.first, x.second.second);
		}
	}

	std::cout << ans << std::endl;

	//system("pause");

	return 0;
}