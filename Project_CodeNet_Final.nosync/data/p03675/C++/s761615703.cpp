#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n, a[500000]; vector<int>p;
int main() {
	cin >> n;
	int B = n; if (n % 2 == 0)B = n - 1;
	for (int i = B; i >= 1; i -= 2)p.push_back(i);
	for (int i = 2; i <= n; i += 2)p.push_back(i);
	if (n % 2 == 0)reverse(p.begin(), p.end());
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << a[p[i - 1]]; }cout << endl;
	return 0;
}