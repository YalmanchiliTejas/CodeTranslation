#include<iostream>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)


int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int sum = r * 100 + g * 10 + b;
	if (sum % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}