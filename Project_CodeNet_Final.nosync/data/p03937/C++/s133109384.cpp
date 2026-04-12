#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int h,w;
	cin >> h >> w;
	int end=1;
	bool flag=true;
	for(int i=0;i<h;i++)
	{
		string s;
		cin >> s;
		int start=-1;
		int n_end=-1;
		for(int j=0;j<w;j++)
		{
			if(start==-1)
			{
				if(s[j]=='#')
					start=j;
			}
			else
			{
				if(s[j]=='.')
				{
					if(n_end==-1)
						n_end=j;
				}
				else
					if(n_end!=-1)
					{
						flag=false;
					}
			}
					
		}
		if(n_end==-1)n_end=w;
		if(start!=end-1)
		{
			flag=false;
		}
		end=n_end;
	}
	cout << (flag ? "Possible":"Impossible") << endl;

}
