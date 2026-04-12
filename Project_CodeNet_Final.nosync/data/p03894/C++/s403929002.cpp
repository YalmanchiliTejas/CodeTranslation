#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Q, tmp = 0;
	cin >> N >> Q;
	vector<int> sim(N), res(N);
	for (int i = 0; i < N; i++) {
		sim[i] = i;
	}
	res[0] = res[1] = 1;
	for (int i = 0, a, b; i < Q; i++) {
		cin >> a >> b;
		swap(sim[a - 1], sim[b - 1]);
		if (sim[a - 1] == 0) {
			tmp = a - 1;
		}
		else if (sim[b - 1] == 0) {
			tmp = b - 1;
		}
		res[sim[max(tmp - 1, 0)]] = res[sim[min(tmp + 1, N - 1)]] = 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (res[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
