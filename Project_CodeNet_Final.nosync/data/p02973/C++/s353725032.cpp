// E - Sequence Decomposing
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (s.size() == 0) {
			s.insert(x);
			continue;
		}
		multiset<int>::iterator it = s.lower_bound(x);
		if (it == s.begin()) {
			s.insert(x);
		} else {
			it--;
			if (*it == x) {
				s.insert(x);
			} else {
				s.erase(it);
				s.insert(x);
			}
		}
	}

	cout << s.size() << endl;

	return 0;
}
