#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n;
int a[N];

int main() {

	FAST;

	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}