#include<iostream>
#include<cstdio>

using namespace std;
int n, cnt[55][30];
string str[55];
int main()
{
	cin>>n;
	for (int i = 0; i < n ;i++)
	{
		cin>>str[i];
	}

	for (int i = 0 ; i < n; i++)
	for (int j = 'a'; j <= 'z'; j++)
		cnt[i][j] = 0;

	for (int i = 0 ; i < n ; i++)
	{
		int len = str[i].length();
		for(int j = 0 ; j < len; j++)
		{
			cnt[i][str[i][j]]++;
		}
	}

	string ans = "";
	for (int i = 'a'; i <='z'; i++)
	{
		int mn = 50;
		for (int j = 0; j < n; j++)
		{
			if (cnt[j][i] < mn) mn = cnt[j][i];
		}
		for (int k = 0; k < mn; k++) ans+=i;
	}

cout<<ans<<endl;

}