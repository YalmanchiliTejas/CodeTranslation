#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string str;
	while(cin >> str)
	{
		if(str[0] == '#')
		{
			break;
		}
		int size = str.size();
		bool right_flag;
		if(str[0] == 'y' || str[0] == 'u' || str[0] == 'i' || str[0] == 'o' || str[0] == 'p' || 
		   str[0] == 'h' || str[0] == 'j' || str[0] == 'k' || str[0] == 'l' || 
		   str[0] == 'n' || str[0] == 'm')
		{
			right_flag = true;
		}
		else
		{
			right_flag = false;
		}
		int count = 0;
		for(int i = 0; i < size; ++i)
		{
			if(str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || str[i] == 'p' || 
			   str[i] == 'h' || str[i] == 'j' || str[i] == 'k' || str[i] == 'l' || 
			   str[i] == 'n' || str[i] == 'm')
			{
				if(right_flag == false)
				{
					right_flag = true;
					count++;
				}
			}
			else
			{
				if(right_flag == true)
				{
					right_flag = false;
					count++;
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