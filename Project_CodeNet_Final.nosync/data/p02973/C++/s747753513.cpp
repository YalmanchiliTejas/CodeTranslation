#include <bits/stdc++.h>

using namespace std;
#define LL long long

#define wt(x) cerr << #x << " is " << x << '\n';
// #define wt(x) cerr << #x << " is " << x << endl;

const int MAXN = 212345;

multiset <int> s;

int main () {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		if (s.empty()) {
			s.insert (x);
			// wt (i);
		}
		else {

			multiset <int> :: iterator it = s.lower_bound (x);

			if (*it == x) {
				if (it == s.begin()) {
					s.insert (x);
				}
				else {
					--it;
					s.erase (it);
					s.insert (x);
				}
			}

			else if (it == s.end()) {
				--it;
				s.erase (it);
				s.insert (x);
			}

			else {
				if (it == s.begin()) {
					s.insert (x);
				}
				else {
					--it;
					s.erase (it);
					s.insert (x);
				}

			}

		}

	}

	int ans = s.size();
	printf("%d\n", ans);


	return 0;
}
