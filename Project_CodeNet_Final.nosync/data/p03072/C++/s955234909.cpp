#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int a = h[0], cnt = 0;
	for (int i = 1; i < n; i++) {
		if (h[i] >= a) {
			cnt++;
			a = h[i];
		}
	}
	cout << cnt+1 << endl;
	return 0;
}
