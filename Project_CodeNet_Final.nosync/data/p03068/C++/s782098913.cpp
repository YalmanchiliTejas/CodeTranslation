#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	string s;
	cin >> s;
	int k;
	cin >> k;
	char n = s[k-1];
	for(int i=0;i<a;i++)
	{
		if(s[i]==n)
		{
			cout << s[i];
		}
		else
		{
			cout << '*';
		}
	}
	cout << endl;
}