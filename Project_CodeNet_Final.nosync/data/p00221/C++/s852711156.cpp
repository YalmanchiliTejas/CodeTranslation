#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;

	cin >> m >> n;

	while (m != 0 || n != 0) {
		queue<int> a;

		for (int i = 0; i < m; i++)
			a.push(i + 1);

		for (int i = 0; i < n; i++) {
			string s;
			bool f = 0;

			cin >> s;

			if ((i + 1) % 15 == 0) {
				if (s != "FizzBuzz")
					f = 1;
			}
			else if ((i + 1) % 3 == 0) {
				if (s != "Fizz")
					f = 1;
			}
			else if ((i + 1) % 5 == 0) {
				if (s != "Buzz")
					f = 1;
			}
			else if (stoi(s) != i + 1)
				f = 1;

			if (f && a.size() > 1)
				a.pop();
			else {
				int b = a.front();
				a.pop();
				a.push(b);
			}
		}

		vector<int> c;

		while (!a.empty()) {
			c.push_back(a.front());
			a.pop();
		}

		sort(c.begin(), c.end());

		for (int i = 0; i < c.size() - 1; i++)
			cout << c[i] << " ";

		cout << c.back() << endl;

		cin >> m >> n;
	}

	return 0;
}

