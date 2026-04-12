#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#define mp make_pair
#define pb push_back

using namespace std;

const int MAX = 2e5 + 5;

int main() 
{
	int n;
	scanf("%d", &n);
	vector<pair<long long, int>> v(n);
	for (int i = 0; i<n; ++i) {
		long long a;
		scanf("%lld", &a);
		v[i] = mp(a,i);
	}
	sort(v.begin(), v.end());
	long long low = v[n/2-1].first, high = v[n/2].first;
	bool res[MAX];
	for (int i = 0; i<n/2; ++i) {
		res[v[i].second] = 1;
	}
	for (int i = n/2; i<n; ++i) {
		res[v[i].second] = 0;
	}
	for (int i = 0; i<n; ++i) {
		if (res[i]) {
			printf("%lld\n", high);
		}
		else {
			printf("%lld\n", low);
		}
	}
	return 0;
}