#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#define INF long long int(1e18+1)
#define MAX 200001
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() {
	long long n, ans = 0;
	cin >> n;
	vector<long long>a(n), s(n + 1, 0);
	rep(i, 0, n) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	rep(i, 0, n) {
		long long int x;
		x = s[n] - s[i + 1];
		x %= 1000000007;
		ans += a[i] * x;
		ans %= 1000000007; 
	}
	cout << ans << endl;
}
