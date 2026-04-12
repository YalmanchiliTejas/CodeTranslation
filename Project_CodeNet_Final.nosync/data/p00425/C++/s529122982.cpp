#include <iostream>
#include <string>

using namespace std;

int solve(string);

int a, b, c;

int main()
{
	int n, sum;
	string s;
	while(cin >> n, n)
	{
		a = 1;
		b = 2;
		c = 3;
		sum = 1;
		while(n--)
		{
			cin >> s;
			sum+=solve(s);
		}
		cout << sum << endl;
	}
}


int solve(string s)
{
	int tmp;
	if(s == "North")
	{
		tmp = a;
		a = b;
		b = 7 - tmp;
	}
	else if(s == "East")
	{
		tmp = c;
		c = a;
		a = 7 - tmp;
	}
	else if(s == "West")
	{
		tmp = a;
		a = c;
		c = 7 - tmp;
	}
	else if(s == "South")
	{
		tmp = b;
		b = a;
		a = 7 - tmp;
	}
	else if(s == "Right")
	{
		tmp = b;
		b = c;
		c = 7 - tmp;
	}
	else if(s == "Left")
	{
		tmp = c;
		c = b;
		b = 7 - tmp;
	}
	return a;
}