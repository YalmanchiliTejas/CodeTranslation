#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	vector<i_i> ai(N);
	rep(i, N) ai[i] = {a[i], i};
	sort(ai.begin(), ai.end());
	vector<int> ans(N);
	rep(i, N)
		if (i < N / 2) ans[ai[i].second] = ai[N / 2].first;
		else ans[ai[i].second] = ai[N / 2 - 1].first;
	rep(i, N) printf("%d\n", ans[i]);
}
