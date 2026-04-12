#include <iostream>

using namespace std;

int main() {
	int m; cin >> m;
	
	for (int prob = 0; prob < m; prob++) {
		
		int depo; cin >> depo;
		int year; cin >> year;
		
		int n; cin >> n;
		
		int ans = 0;
		
		for (int method = 0; method < n; method++) {
			int hukuri;
			double nennri;
			int tesuu;
			cin >> hukuri >> nennri >> tesuu;
			
			int cur = depo;
			
			if (hukuri==1) {
				int A = cur;
				for (int y = 0; y<year; y++) {
					int B = (int)(A * nennri);
					A = A + B - tesuu;
				}
				cur = A;
			} else {
				int A = cur;
				int BSUM = 0;
				for (int y=0; y<year; y++) {
					int B = (int)(A*nennri);
					A = A - tesuu;
					BSUM += B;
				}
				cur = A + BSUM;
			}
			
			ans = max(ans, cur);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}