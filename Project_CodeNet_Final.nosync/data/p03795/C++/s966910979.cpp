#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,ans;
	cin >> n;
	ans = (800 * n) - ((n / 15) * 200);
	cout << ans << endl;
	return 0;
}