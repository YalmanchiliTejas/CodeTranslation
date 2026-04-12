#include "bits/stdc++.h"
using namespace std;

int main() {
	
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for (int i=0; i<n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr, arr+n);
	
	int res[n];
	for (int i=0; i<n; i++) {
		
		if (i < (n/2)) {
			res[arr[i].second] = arr[n/2].first;
		}
		else {
			res[arr[i].second] = arr[n/2-1].first;
		}
		
	}
	
	for (int i=0; i<n; i++) cout << res[i] << endl;
	
}
