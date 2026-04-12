#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int Min(int a, int b, int c) {
	if (a <= b) { return std::min(a, c); }
	else return std::min(b, c);
}
int Max(int a, int b, int c) {
	if (a >= b) { return std::max(a, c); }
	else return std::max(b, c);
}
int main(void) {
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n)cin >> v[i];
	int ans = 1;
	bool f = false;
	for (int i = 0; i < n; i++) {
		for (int wi = 0; wi < i; wi++) {
			if (v[i] < v[wi])f = false;
		}
		if (f)ans++;
		f = true;
	}
	cout << ans << endl;
	return 0;
}