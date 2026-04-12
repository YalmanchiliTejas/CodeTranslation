#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	int m, n;
	while (cin >> m >> n&&m != 0 && n != 0) {
		list<int>a;
		for (int i = 1; i <= m; i++) a.push_back(i);
		list<int>::iterator it = a.begin(), it2;
		for (int z = 1; z <= n; z++) {
			string b;
			cin >> b;
			if (a.size() != 1) {
				if ((z % 3 == 0 && z % 5 != 0 && b == "Fizz") ||
					(z % 5 == 0 && z % 3 != 0 && b == "Buzz") ||
					(z % 5 == 0 && z % 3 == 0 && b == "FizzBuzz") ||
					(z % 3 != 0 && z % 5 != 0 && b == to_string(z))) {
					it++;
				}
				else {
					it2 = it;
					it2++;
					a.erase(it);
					it = it2;
				}
				if (it == a.end()) {
					it = a.begin();
				}
			}
		}
		it = a.begin();
		while (it != a.end()) {
			if (it == a.begin()) cout << (*it);
			else cout << " " << (*it);
			it++;
		}
		cout << endl;
	}
}