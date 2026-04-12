#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include <string>
#include <numeric>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
map<int, int> mp;
map<int, int>mm;
#define ll long long
#define ld long double
#define PI 3.14159265358979l

int gcd(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}


int main() {
	int n, h[100];
	cin >> n;
	int ans = 1;
	rep(i, n)cin >> h[i];
	for (int i = 1; i < n;i++) {
		bool a = true;
		rep(j, i) {
			if (h[i] < h[j])a = false;
		}
		if (a)ans++;
	}
	cout << ans << endl;
	cin >> n;
	return 0;
}