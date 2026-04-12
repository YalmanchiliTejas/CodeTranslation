#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	char a[3];
	for (int i = 0; i < 3; i++) cin >> a[i];
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == 'A') t1++;
		else t2++;
	}
	if (t1 == 1 || t2 == 1) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
