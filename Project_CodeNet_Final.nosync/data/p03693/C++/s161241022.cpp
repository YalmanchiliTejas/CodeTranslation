#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	string rgb = a + b + c;
	int abc = stoi(rgb);

	if (abc % 4 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;

}
