#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, r = 0;
	cin >> n;
	int x [n];
	for(int i = 0; i < n; i++) cin >> x[i];
	priority_queue <int> A; A.push(0);
	for(int i = 0; i < n; i++){
		if(A.top() <= x[i]) r++;
		A.push(x[i]);
	}
	cout << r << endl;
	return 0;
}
