#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 4;
int b[maxn];
pii a[maxn];

int main () {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) {
			b[a[i].S] = a[n / 2 + 1].F;
		}
		else {
			b[a[i].S] = a[n / 2 + 0].F;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << b[i] << " ";
}
