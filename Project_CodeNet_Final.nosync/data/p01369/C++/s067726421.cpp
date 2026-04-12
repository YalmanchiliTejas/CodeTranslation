


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <functional>

using namespace std;

int INF = 10000000;

int table[] = 
{
	0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0
};



int main()
{
	string str;
	while(cin >> str && str != "#")
	{
		int sum = 0;
		int flag = table[str[0] - 'a'];
		for(int i = 0;i < str.length();i++)
		{
			if(flag != table[str[i] - 'a'])
			{
				sum++;
				flag = 1-flag;
			}
		}

		cout << sum << endl;
	}

  return 0;
}