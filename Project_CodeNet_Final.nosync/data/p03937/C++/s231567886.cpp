#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int h;
int w;

int cou = 0;
int main()
{
	cin >> h >> w;

	for(int i = 1;i <= h;i++){
		string s;
		cin >> s;
		for(int j = 1;j <= w;j++)
		{
			if(s[j - 1] == '#')
			{
				cou++;
			}
		}
	}


	if(cou == h + w - 1)
	{
		cout << "Possible" << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}
	return 0;
}

