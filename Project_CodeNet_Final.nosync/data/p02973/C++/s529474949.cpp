#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;

int n, a;
multiset<int> s;
multiset<int> :: iterator it;

int main () {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a;
		if (s.size() == 0) {
			k ++;
			s.insert(a);
		}
		else {
			it = s.lower_bound(a);
			if (it == s.begin()) {
				k ++;
				s.insert(a);
			}
			else {
				it --;
				s.erase(it);
				s.insert(a);
			}
		}
	}
	
	cout << k;

	return 0;
}