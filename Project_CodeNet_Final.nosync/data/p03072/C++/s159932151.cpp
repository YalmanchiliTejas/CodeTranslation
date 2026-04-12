#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, ans = 1, ma;
	cin >> n >> ma;

	for(int i=0;i<n-1;i++){
		int h;
		cin >> h;
		if(ma<=h){
			ma = h;
			ans++;
		}
	}
	cout << ans << endl;
}