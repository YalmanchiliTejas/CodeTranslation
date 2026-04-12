#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long a[50], k;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	while(1) {
		long long mm = 0;
		int j = -1;
		for(int i = 0; i < n; i++) {
			if(a[i] > mm) {
				j = i;
				mm = a[i];
			}
		}
		
		if(mm < n) break;
		
		long long dk = a[j] / n;
		k += dk;
		a[j] %= n;
		for(int i = 0; i < n; i++) {
			if(i == j) continue;
			a[i] += dk;
		}
	}
	
	cout << k << '\n';
	
	
	
	return 0;
}