#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int max = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(max <= v[i]) {
			max = v[i];
			ans++;
		}
	}
	
	cout << ans << endl;
	return 0;
}