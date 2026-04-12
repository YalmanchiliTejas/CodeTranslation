#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
int main(void) {
	int n, a[20],m[20],ans= 0;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (i == 0) {
			m[i] = a[i];
		}
		else {
			m[i] = max(m[i - 1], a[i]);
		}
	}
	rep(i, n) {
		if (a[i] >= m[i]) {
			ans++;
		}
	}
	cout << ans << endl;
}