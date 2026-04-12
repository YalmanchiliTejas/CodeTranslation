#include <bits/stdc++.h>
using namespace std;

int main () {

	multiset <int> s;
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int x;
		scanf ("%d", &x);
		multiset <int> :: iterator it = s.lower_bound (x);
		if (it == s.begin())
			s.insert (x);
		else {
			--it;
			s.erase (it);
			s.insert (x);
		}
	}

	cout << s.size() << endl;

	return 0;
}