#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	long long n,ans;

	cin >> n;

	ans = n * 800 - n / 15 * 200;

	cout << ans << endl;
}