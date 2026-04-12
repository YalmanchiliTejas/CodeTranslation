#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int N, M;
 
void solve() {
	cin >> N >> M;
	if (N == M) {
		cout << "Yes" << endl;
	} 
	else {
		cout << "No" << endl;
	}
 
}
 
int main() {
	solve();
	return 0;
}