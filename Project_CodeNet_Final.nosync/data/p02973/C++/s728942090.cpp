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
		multiset<int>::iterator it = s.lower_bound(x);
		if (it != s.begin()) s.erase(--it);
		s.insert(x);
	}
	cout << s.size() << endl;

	return 0;
}
