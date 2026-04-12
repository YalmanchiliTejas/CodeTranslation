#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
bool can(int x) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		sum -= x;
		if(sum < 0) {
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 1, r = 100;
	while(r - l > 1) {
		int mid = (l + r) / 2;
		if(can(mid)) l = mid;
		else r = mid;
	}
	cout << (can(l) ? l : r) << endl;
	return 0;	
}

