#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n; int t,k[100],s=1;
	bool q=true;
	cin >> n;
	n--;
	cin>>k[0];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		t = k[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (t < k[j]) q = false;
		}
		if (q) s++;
		q = true;
	}
	cout << s;
}
