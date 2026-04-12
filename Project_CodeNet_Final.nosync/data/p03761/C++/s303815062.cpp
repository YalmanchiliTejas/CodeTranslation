#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[100][27];

int main()
{
	ll n;
	cin >> n;

	for (int i = 1;i <= n;i++)
	{
		string str;
		cin >> str;
		for (int j = 0;j < str.size();j++)
		{
			lst[i][str[j] - 'a']++;
		}
	}
	for (int i = 0;i <= 25;i++)
	{
		int g = 1e9 + 5;
		for (int j = 1;j <= n;j++)
		{
			g = min(lst[j][i], g);
		}
		for (int j = 1;j <= g;j++)cout << char(i + 'a');
	}
}