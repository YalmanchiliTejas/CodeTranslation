#include<iostream>
using namespace std;
int n, ans;
int main()
{
	cin >> n;
	ans = n / 15 * 200;
	cout << n * 800 - ans << endl;
	return 0;
}