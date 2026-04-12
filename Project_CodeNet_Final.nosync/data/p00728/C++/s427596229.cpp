#include <bits/stdc++.h>

using namespace std;

#define rep(i, a) for (int (i) = 0; (i) < (a); (i)++)
#define reps(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define MP(a, b) make_pair((a), (b))
#define pb(a) push_back((a))
#define all(v) (v).begin(), (v).end()


int main()
{
	int n;
	int p;
	int ma, mi;
	cin >> n;
	while (n) {
		int sum = 0;
		ma = 0;
		mi = 1000;
		rep(i, n) {
			cin >> p;
			sum += p;
			ma = max(ma, p);
			mi = min(mi, p);
		}
		cout << (sum-ma-mi) / (n-2) << endl;
		cin >> n;
	}
}



