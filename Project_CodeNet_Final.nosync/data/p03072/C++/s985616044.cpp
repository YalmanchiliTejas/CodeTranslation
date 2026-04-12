#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main() { 
	int n; cin >> n;
	int h;
	int maxh = 0; int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (maxh <= h) {
			ans++;
			maxh = h;
		}
	}
	cout << ans << endl;
	return 0;
}