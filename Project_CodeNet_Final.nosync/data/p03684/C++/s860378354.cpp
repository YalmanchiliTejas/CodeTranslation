#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct road {
	int cost;
	int city1;
	int city2;
};

int root[100000];


int getRoot(int city)
{
	if (root[city] == city) return city;
	return getRoot(root[city]);
}

void setRoot(int city, int to)
{
	if (root[city] != city) {
		setRoot(root[city], to);
	}
	root[city] = to;
	return;
}

bool cost_sort(const road& a, const road& b)
{
	return a.cost < b.cost;
}

int main(void) {
	int N;
	cin >> N;
	vector <pair<int, int> > X;
	vector <pair<int, int> > Y;
	long long cost[2] = {0};
	for (int i = 0; i < N; i++) {
		int x, y;		
		cin >> x >> y;
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
	}

	std::sort(X.begin(), X.end());
	std::sort(Y.begin(), Y.end());

	vector <road> R;
	for (int i = 0; i < N-1; i++) {
		road r;
		r.cost  = X[i+1].first - X[i].first;
		r.city1 = X[i+1].second;
		r.city2 = X[i].second;
		R.push_back(r);

		r.cost  = Y[i+1].first - Y[i].first;
		r.city1 = Y[i+1].second;
		r.city2 = Y[i].second;
		R.push_back(r);
	}

	std::sort(R.begin(), R.end(), cost_sort);

	for (int i = 0; i < N; i++) root[i] = i;

	long long total_cost = 0;
	for (int i = 0; i < R.size(); i++) {
		int rootA = getRoot(R[i].city1);
		int rootB = getRoot(R[i].city2);

		if (rootA == rootB) continue;

		total_cost += R[i].cost;
		setRoot(R[i].city1, rootB);
	}
	cout << total_cost << endl;
	return 0;
}
