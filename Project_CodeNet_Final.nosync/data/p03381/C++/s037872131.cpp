#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>

using namespace std;
typedef long long ll;

ll N, X[200001] = {}, Y[200001] = {};

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> X[i];
		Y[i] = X[i];
	}
	stable_sort(X, X + N + 1);
	for (int i = 1; i <= N; i++) {
		if (Y[i] <= X[N / 2]) {
			cout << X[N / 2 + 1] << endl;
		}
		else {
			cout << X[N / 2] << endl;
		}
	}
	return 0;
}