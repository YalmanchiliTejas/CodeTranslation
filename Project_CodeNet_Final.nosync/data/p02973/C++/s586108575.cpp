#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vector<int> a(n); rep(i, n) cin >> a[i];

	deque<int> deq;
	rep(i, n) {
		int p = lower_bound(deq.begin(), deq.end(), a[i]) - deq.begin();
		if (p == 0) deq.push_front(a[i]);
		else deq[p - 1] = a[i];
	}
	cout << deq.size() << endl;
	return 0;
}
