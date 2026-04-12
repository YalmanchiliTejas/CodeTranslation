#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string s[n];
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	char c = 'a';
	int cnt[n][26] = {0};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < s[i].size(); j++)
		{
			cnt[i][s[i][j] - 'a']++;
		}
	}
	
	int a[26] = {0};
	for(int i = 0; i < 26; i++)
	{
		bool flag = true;
		int min = 99999;
		
		for(int j = 0; j < n; j++)
		{
			if(cnt[j][i] < min && cnt[j][i] != 0)
			{
				min = cnt[j][i];
			}
			
			if(cnt[j][i] == 0)
			{
				flag = false;
				break;
			}
		}
		
		if(flag == true)
		{
			while(min > 0)
			{
				cout << char('a' + i);
				min--;
			}
		}
	}
	
	cout << endl;
	return 0;
}