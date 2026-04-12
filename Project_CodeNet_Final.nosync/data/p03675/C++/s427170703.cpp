#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	deque<int> v;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (i % 2 == 0) {
			v.push_back(a);
		}
		else {
			v.push_front(a);
		}
	}
	if (n % 2 != 0) {
		reverse(v.begin(), v.end());
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cout << v[i];
		} else{
			cout << " " << v[i];
		}
	}
	cout << endl;
}
