#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	string ans = "NO";
	if (n == 3 || n == 5 || n == 7) {
		ans = "YES";
	}
	cout << ans;
	return 0;
}