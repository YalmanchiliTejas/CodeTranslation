#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<long long> scorelist;

int main() {
	int r,g,b;
	cin >> r >> g >> b;

	if ((r * 100 + g * 10 + b * 1) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	

	return 0;
}
