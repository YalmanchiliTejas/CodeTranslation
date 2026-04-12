#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int h[21];
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	int m = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		m = max(m, h[i]);
		if(m<=h[i]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}