#include <iostream>
#include <string>
using namespace std;

string ls="qwertasdfgzxcvb";

int main()
{
	string s;
	while(cin >> s, s!="#")
	{
		bool l=false;
		for(int i=0; i<ls.size(); i++)
			if(ls[i]==s[0]) l=true;

		int ret=0;
		for(int i=1; i<s.size(); i++)
		{
			bool lr=false;
			for(int j=0; j<ls.size(); j++)
			{
				if(ls[j]==s[i]) 
				{
					if(!l) ret++;
					l=true;
					lr=true;
				}
			}
			if(!lr&&l)
			{
				l=false;
				ret++;
			}
		}

		cout << ret << endl;
	}
}