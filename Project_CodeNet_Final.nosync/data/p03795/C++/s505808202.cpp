#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	int ans = n * 800;
	int y = n / 15;
	ans -= y * 200;
	cout << ans << endl;
	
	return 0;
}