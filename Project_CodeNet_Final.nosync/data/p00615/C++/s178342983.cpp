#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int main() {
	int n, m, x;
	while (cin >> n >> m&&(n != 0||m!=0)) {
		multiset<int>a;
		a.insert(0);
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.insert(x);
		}
		for (int j = 0; j < m; j++) {
			cin >> x;
			a.insert(x);
		}
		multiset<int>::iterator it = a.begin();
		it++;
		int sa = 0;
		for (int i = 1; i <= n + m; i++) {
			sa = max(sa, (*it) - (*--it));
			it++;
			it++;
		}
		cout << sa << endl;
	}
}