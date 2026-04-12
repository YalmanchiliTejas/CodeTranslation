#include <bits/stdc++.h>
using namespace std;

string x;
int a=0, b=0;

int main()
{
	cin >> x;
	for(int i=0; i<3; i++)
	{
		if(x[i] == 'A') a++;
		else b++;
	}
	
	if(a!=0 and b!=0) cout << "Yes\n";
	else cout << "No\n";
}