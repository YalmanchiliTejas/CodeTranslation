#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	while (1) {
		int n; cin >> n; if (n==0) break;
		
		vector<int> score(n);
		for (int i=0; i<n; i++) cin >> score[i];
		
		sort(score.begin(), score.end());
		int sum = 0;
		for (int i=1; i<n-1; i++) sum += score[i];
		cout << sum/(n-2) << endl;
	}
	
	return 0;
}