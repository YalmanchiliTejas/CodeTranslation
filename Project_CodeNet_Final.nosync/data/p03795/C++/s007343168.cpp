#include<iostream>
#include<vector>
#define debug_C(a) cout << a << endl;
using namespace std;
int main() {
	int x=0, y=0,N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		x += 800;
		if (i % 15 == 0) y += 200;
	}
	cout << x - y << endl;
	

	return 0;
}