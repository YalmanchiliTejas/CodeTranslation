#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string str;
	while(cin >> str, str != "#")
	{
		bool flag;
		if(str[0] == 'y' || str[0] == 'u' || str[0] == 'i' || str[0] == 'o' || 
		   str[0] == 'p' || str[0] == 'h' || str[0] == 'j' || str[0] == 'k' || 
		   str[0] == 'l' || str[0] == 'n' || str[0] == 'm')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		int count = 0;
		for(int i = 0; i < str.size(); ++i)
		{
			if(!flag)
			{
				if(str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || 
				   str[i] == 'p' || str[i] == 'h' || str[i] == 'j' || str[i] == 'k' || 
				   str[i] == 'l' || str[i] == 'n' || str[i] == 'm')
				{
					flag = !flag;
					++count;
				}
			}
			else
			{
				if(!(str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || 
				   str[i] == 'p' || str[i] == 'h' || str[i] == 'j' || str[i] == 'k' || 
				   str[i] == 'l' || str[i] == 'n' || str[i] == 'm'))
				{
					flag = !flag;
					++count;
				}
			}
		}
		cout << count << endl;
	}
}

int main()
{
	solve();
	return(0);
}