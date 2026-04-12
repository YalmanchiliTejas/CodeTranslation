#include<iostream>
#include<string>
#include<complex>
#include<vector>
#include<algorithm>
#include<functional>
#include<array>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF 1e+9


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ans = false;

	vector<char> v(100005);
	v[1] = 'S'; v[2] = 'S';
	for (int i = 2;i < n+3;i++) {
		if (v[i] == 'S'&&s[(i - 1) % n] == 'o') v[i + 1] = v[i - 1];
		if (v[i] == 'W'&&s[(i - 1) % n] == 'x') v[i + 1] = v[i - 1];
		if (v[i] == 'S'&&s[(i - 1) % n] == 'x') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
		if (v[i] == 'W'&&s[(i - 1) % n] == 'o') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
	}
	if (v[n+1] ==v[1]) if (v[n +2] == v[2]) ans = true;
	if (ans == true) { for (int i = 1;i <= n;i++) cout << v[i];cout << endl; return 0; }
	
	v[1] = 'W'; v[2] = 'S';
	for (int i = 2;i < n + 3;i++) {
		if (v[i] == 'S'&&s[(i - 1)%n] == 'o') v[i + 1] = v[i - 1];
		if (v[i] == 'W'&&s[(i - 1)%n] == 'x') v[i + 1] = v[i - 1];
		if (v[i] == 'S'&&s[(i - 1)%n] == 'x') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
		if (v[i] == 'W'&&s[(i - 1)%n] == 'o') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
	}
	if (v[n + 1] == v[1]) if (v[n + 2] == v[2]) ans = true;
	if (ans == true) { for (int i = 1;i <= n;i++) cout << v[i];cout << endl; return 0; }

	v[1] = 'S'; v[2] = 'W';
	for (int i = 2;i < n + 3;i++) {
		if (v[i] == 'S'&&s[(i - 1) % n] == 'o') v[i + 1] = v[i - 1];
		if (v[i] == 'W'&&s[(i - 1) % n] == 'x') v[i + 1] = v[i - 1];
		if (v[i] == 'S'&&s[(i - 1) % n] == 'x') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
		if (v[i] == 'W'&&s[(i - 1) % n] == 'o') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
	}
	if (v[n + 1] == v[1]) if (v[n + 2] == v[2]) ans = true;
	if (ans == true) { for (int i = 1;i <= n;i++) cout << v[i];cout << endl; return 0; }

	v[1] = 'W'; v[2] = 'W';
	for (int i = 2;i < n + 3;i++) {
		if (v[i] == 'S'&&s[(i - 1) % n] == 'o') v[i + 1] = v[i - 1];
		if (v[i] == 'W'&&s[(i - 1) % n] == 'x') v[i + 1] = v[i - 1];
		if (v[i] == 'S'&&s[(i - 1) % n] == 'x') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
		if (v[i] == 'W'&&s[(i - 1) % n] == 'o') if (v[i - 1] == 'S') v[i + 1] = 'W';else v[i + 1] = 'S';
	}
	if (v[n + 1] == v[1]) if (v[n + 2] == v[2]) ans = true;
	if (ans == true) { for (int i = 1;i <= n;i++) cout << v[i];cout << endl; return 0; }

	cout << -1 << endl;

	return 0;
}