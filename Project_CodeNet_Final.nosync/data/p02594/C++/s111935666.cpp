#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a;
	cin >> a;
	if (a < 30) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}