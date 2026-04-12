#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int order[200001];

int main(void)
{
	int N;
	cin >> N;

	int center_pos = N/2;
	vector <pair <int, int> > X;
	for (int pos = 1; pos<= N; pos++) {
		int x;
		cin >> x;
		X.push_back(make_pair(x, pos));
	}
	std::sort(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		order[X.at(i).second] = i+1;
	}
	int center_val = X.at(center_pos-1).first;
	int center_plus_val = X.at(center_pos).first;

	for (int i = 1; i <= X.size(); i++) {
		if (order[i] <= center_pos) {
			cout << center_plus_val << endl;
		} else {
			cout << center_val << endl;
		}
	}

	return 0;
}
