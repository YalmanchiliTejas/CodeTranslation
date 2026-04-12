#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

constexpr int MAXN = 200000;

pair<int, int> X[MAXN + 2];
int ans[MAXN + 2];

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> X[i].first;
		X[i].second = i;
	}
	sort(X, X + N);
	for(int i = 0; i < N / 2; i++)
		ans[X[i].second] = X[N / 2].first;
	for(int i = N / 2; i < N; i++)
		ans[X[i].second] = X[N / 2 - 1].first;
	for(int i = 0; i < N; i++)
		cout << ans[i] << '\n';
}
