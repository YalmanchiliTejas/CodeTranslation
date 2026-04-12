#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MOD 1000000007

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}

int d[100000 * 3];

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int sum = z * 100 + y * 10 + z;
	if (0 == sum % 4)cout << "YES" << endl;
	else cout << "NO" << endl;
}