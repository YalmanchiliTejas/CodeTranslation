#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
typedef vector<int> VI;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())

int main() {

	int n, ans = 1, h[20], m;
	cin >> n;
	FOR(i, n)cin >> h[i];
	m = h[0];
	FOR(i, n - 1) {
		if (m <= h[i + 1]) {
			ans++;
			m = h[i + 1];
		}
	}

	cout << ans << endl;

	return 0;
}
