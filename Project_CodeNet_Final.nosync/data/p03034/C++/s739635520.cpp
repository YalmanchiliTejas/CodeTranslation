#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int s[100000];

signed main() {
	int i;
	
	cin >> n;
	rep(i, n) cin >> s[i];
	
	int ans = 0;
	
	int a, b;
	int c;	//a-b
	for (c = 1; c <= n - 2; c++) {
		vector<int> rui1;	//mc
		vector<int> rui2;	//(n-1)%c + mc
		int m;
		
		int su1 = 0, su2 = 0;
		rui1.push_back(0);
		for (m = 0; m * c < n; m++) {
			rui1.push_back(*rui1.rbegin() + s[m * c]);
		}
		su1 = *rui1.rbegin();
		
		rui2.push_back(0);
		for (m = 0; (n - 1) % c + m * c < n; m++) {
			rui2.push_back(*rui2.rbegin() + s[(n - 1) % c + m * c]);
		}
		su2 = *rui2.rbegin();
		
		//cout << "c = " << c << endl;
		//rep(i, rui1.size()) cout << rui1[i] << " "; cout << endl;
		//rep(i, rui2.size()) cout << rui2[i] << " "; cout << endl;
		
		m = -1;
		for (a = (n - 1) % c; a < n; a += c) {
			m++;
			int b = a - c;
			if (b <= 0) continue;
			if (a % c == 0 && a + b < n - 1) continue;
			//cout << a << ", " << b << endl;
			
			int score = su2 - rui2[m] + rui1[(n - 1 - a) / c + 1];
			//cout << "a, b = " << a << ", " << b  << ", score = " << score << endl;
			ans = max(score, ans);
		}
	}
	cout << ans << endl;
	return 0;
}