#include <bits/stdc++.h>
using namespace std;
//const int INF = 0x3f3f3f3f;
//map<int,int> rr;
int main()
{
	char s[4];
	for (int i = 0; i < 3;i++)
	{
		cin >> s[i];
	}
	int flag = 0;
	for (int i = 0; i < 2;i++)
	{
		if(s[i]!=s[i+1])
		{
				flag = 1;
				break;
		}
	}
	if(flag==0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}