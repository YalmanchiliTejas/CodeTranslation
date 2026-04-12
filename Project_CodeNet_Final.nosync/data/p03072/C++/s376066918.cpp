#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int i = 0, N;
	cin >> N;

	vector<int> high(N);

	while (i < N) {
		cin >> high.at(i);
		i++;
	}

	int j = 0, k = 0, ans = 0;
	while (j < N) {
		while (k < j) {
			if (high.at(k) > high.at(j)) {
				break;
			}
			k++;
		}
		if (k == j) {
			ans++;
		}
		k = 0;
		j++;
	}
	
	cout << ans << endl;
	
	return 0;
}