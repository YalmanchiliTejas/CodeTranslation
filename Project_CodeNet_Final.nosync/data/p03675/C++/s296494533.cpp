#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int (i) = 0; (i) != (n); (i)++)
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> left, right;

	rep(i, n) {
		int temp; cin >> temp;
		if (i % 2 == 0)
			right.push_back(temp);
		else
			left.push_back(temp);
	}
	if (n % 2 == 0) {
		rep(i, left.size())
			cout << left[left.size() - 1 - i] << " ";
		rep(i, right.size()) {
			if (i == right.size() - 1)
				cout << right[i] << endl;
			else
				cout << right[i] << " ";
		}
	}
	else {
		rep(i, right.size())
			cout << right[right.size() - 1 - i] << " ";
		rep(i, left.size()) {
			if (i == left.size() - 1)
				cout << left[i] << endl;
			else
				cout << left[i] << " ";
		}
	}

	return 0;
}

