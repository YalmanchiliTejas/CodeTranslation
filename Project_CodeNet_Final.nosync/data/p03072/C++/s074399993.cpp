#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int  main()
{
	int N; cin >> N;
	vector<int> h(N);
	int cnt = 1;
	priority_queue<int> q;
	rep(i, N)
		cin >> h[i];
	q.push(h[0]);
	rep1(i, N)
	{
		if (q.top() <= h[i])
			cnt++;
		q.push(h[i]);
	}
	cout << cnt << endl;
	return (0);
}