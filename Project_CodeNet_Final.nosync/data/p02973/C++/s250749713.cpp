#include <iostream> 
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	multiset<int> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i]);
		if (it == s.begin()) {
			//cout << "insert: " << a[i] << endl;
			s.insert(a[i]);
		} else {
			it --;
			//cout << "delete: " << *(it) << endl;
			//cout << "new: " << a[i] << endl;

			s.erase(it);
			s.insert(a[i]);
		}

	}
	cout << s.size() << endl;


	return 0;

}