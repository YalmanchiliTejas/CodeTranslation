#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int m, n;
	while (cin >> m >> n, m, n) {
		queue<int>v;
		for (int i = 1; i <= m; i++)v.push(i);

		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			if (v.size() == 1)continue;
				if (i % 15 == 0) {
					int a = v.front();
					if (s == "FizzBuzz") {
						v.pop();
						v.push(a);
					}
					else v.pop();
				}

				else if (i % 3 == 0) {
					int a = v.front();
					if (s == "Fizz") {
						v.pop();
						v.push(a);
					}
					else v.pop();
				}

				else if (i % 5 == 0) {
					int a = v.front();
					if (s == "Buzz") {
						v.pop();
						v.push(a);
					}
					else v.pop();
				}

				else {
					int a = v.front();
					string sa = to_string(i);
					if (s == sa) {
						v.pop();
						v.push(a);
					}
					else v.pop();
			}
		}
		vector<int>va;
		while (v.size()) {
			va.push_back(v.front());
			v.pop();
		}
		sort(va.begin(), va.end());
		for (int i = 0; i < va.size(); i++) {
			if (i)cout << ' ';
			cout << va[i];
		}
		cout << endl;
	}
	return 0;
}