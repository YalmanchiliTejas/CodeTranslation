/* 
	Author: ankrypt
*/
#include <bits/stdc++.h>

using namespace std;

string S;
int sizeOfString;
int flag = 0;

int main()
{
	cin >> S;
	sizeOfString = S.size();
	for(int i = 1; i < sizeOfString; i++)
	{
		if(S[i] == 'C' && S[i - 1] == 'A')
		{
			flag++;
		}
	}
	if(flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
}
/*
	Powered by Buggy Plugin
*/
