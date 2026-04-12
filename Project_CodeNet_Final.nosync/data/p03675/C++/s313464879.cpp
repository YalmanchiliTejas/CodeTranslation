#include<iostream>
#include<deque>
using namespace std;

int main() {
	int n; cin >> n;
	deque<int>a;
	for (int i = 0,tmp; i < n; i++) {
		cin >> tmp;
		if (n % 2 == 0) {
			if (i % 2 != 0)a.push_front(tmp);
			else a.push_back(tmp);
		}
		else {
			if (i % 2 == 0)a.push_front(tmp);
			else a.push_back(tmp);
		}
	}
	for (auto&& x : a)cout << x << ' '; cout << endl;

	return 0;
}