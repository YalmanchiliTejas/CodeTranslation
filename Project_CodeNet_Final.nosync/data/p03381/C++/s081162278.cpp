#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
int arr[MAX], ans[MAX];
int n;

int main() {
	scanf("%d", &n);

	vector<ii> v;
	fori(i, 1, n + 1) {
		scanf("%d", arr + i);
		v.emplace_back(arr[i], i);
	}

	sort(v.begin(), v.end());

	fori(i, 0, n) {
		if(i < n / 2) {
			ans[v[i].second] = v[n / 2].first;
		}
		else {
			ans[v[i].second] = v[n / 2 - 1].first;
		}
	}

	fori(i, 1, n + 1) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
