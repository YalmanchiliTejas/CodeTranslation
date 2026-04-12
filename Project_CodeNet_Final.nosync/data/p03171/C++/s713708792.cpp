#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int64_t memo[3001][3001][2];
int64_t a[3000];
//
int64_t f(int l, int r, int state) {
	if (l > r) return 0;
	if (memo[l][r][state] != 0) return memo[l][r][state];
	int64_t ret = 0;
	if (state == 0) {
		ret = max(f(l+1, r, 1) + a[l], f(l, r-1, 1) + a[r]);
	} else {
		ret = min(f(l+1, r, 0) - a[l], f(l, r-1, 0) - a[r]);
	}
	return memo[l][r][state] = ret;
	return ret;
}

int main(int argc, char **argv) {

	cin.tie(0);
  	ios::sync_with_stdio(false);

  	int n;
  	cin >> n;
  	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

  	cout << f(0, n-1, 0) << endl;

}
