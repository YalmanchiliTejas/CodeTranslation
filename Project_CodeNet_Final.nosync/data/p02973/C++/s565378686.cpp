#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> List;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		auto itr = upper_bound(List.begin(), List.end(), -A);
		if (itr == List.end()) List.push_back(-A);
		else *itr = -A;
	}
	cout << List.size() << endl;
}
