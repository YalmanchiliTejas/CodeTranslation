#include "bits/stdc++.h"
#define ed cout<<"\n";
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	SPEED;
	int n;
	int h[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int counts = 1;
	for (int i = 1; i < n; i++) {
		bool flag = false;
		
		for (int j =0; j < i; j++) {
			if (h[i] >= h[j]) {
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			counts++;
		}
	}
	cout << counts;
	ed;
	return 0;
}