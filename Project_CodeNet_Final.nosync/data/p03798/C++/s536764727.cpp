#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

#define SHEAP 'S'
#define WOLF 'W'
#define SAME 'o'
#define NOTSAME 'x'

bool isOk(int pos, const string& s, const string& temp)
{
	int left = pos-1, right = pos+1;
	if(pos == 0)
		left = temp.size() - 1;
	else if(pos == temp.size() - 1)
		right = 0;

	bool flag = true;
	if(s[pos] == SAME && temp[left] != temp[right])
		flag = false;
	else if(s[pos] == NOTSAME && temp[left] == temp[right])
		flag = false;

	if(temp[pos] == WOLF)
		flag = !flag;

	return flag;
}

int main(void)
{
	int N;
	cin >> N;

	string s;
	cin >> s;
	
	const string animal = "SW";
	string ret = "-1";
	for(int i=0; i<2; i++)
	{
		string temp = s;
		temp[0] = animal[i];

		for(int j=0; j<2; j++)
		{
			temp[1] = animal[j];
			
			for(int k=1; k<N-1; k++)
			{
				char c = temp[k-1];
				if(temp[k] == SHEAP && s[k] == NOTSAME)
					c = (c == animal[0]) ? animal[1] : animal[0];
				else if(temp[k] == WOLF && s[k] == SAME)
					c = (c == animal[0]) ? animal[1] : animal[0];

				temp[k+1] = c;
			}

			if(isOk(0, s, temp) && isOk(N-1, s, temp))
			{
				ret = temp;
				i = j = 3;
			}
		}
	}
	
	cout << ret << endl;

	return 0;
}
