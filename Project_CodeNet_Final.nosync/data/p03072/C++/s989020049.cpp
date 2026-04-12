#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int max_height = -1;
	int can_see = 0;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		
		if(val >= max_height) can_see++;
		max_height = max(max_height, val);
	}
	
	cout << can_see;
	
	return 0;
}