#include <iostream>
using namespace std;

int main() {
	int n;cin >> n;
	bool ans = 0;
	if(n == 3)ans = 1;
	if(n == 5)ans = 1;
	if(n == 7)ans = 1;
	if(ans)cout << "YES";
	else cout << "NO";
	return 0;
}