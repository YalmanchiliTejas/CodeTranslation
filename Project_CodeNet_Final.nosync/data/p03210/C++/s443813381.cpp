#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	if (!(n == 1))cout << (3 * 5 * 7 % n == 0 ? "YES" : "NO") << endl;
	else cout << "NO" << endl;
}