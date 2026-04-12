#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int m,n; string s;

	while(cin >> m >> n, m||n)
	{
		int prevplayer = m-1;
		int currplayer = 0;
		int nextplayer[1024];

		for(int i=0; i<m; i++)
		{
			nextplayer[i] = (i+1)%m;
		}

		bool flag = true;
		for(int i=1; i<=n; i++)
		{
			cin >> s;

			if(flag)
			{
				stringstream ans;

				if(i%3==0 && i%5==0)	ans << "FizzBuzz";
				else if(i%3==0)			ans << "Fizz";
				else if(i%5==0)			ans << "Buzz";
				else					ans << i;

				
				if(s == ans.str())
				{
					prevplayer = currplayer;
					currplayer = nextplayer[currplayer];
				}
				else
				{
					nextplayer[prevplayer] = nextplayer[currplayer];
					nextplayer[currplayer] = -1;
					currplayer = nextplayer[prevplayer];		
				}

				if(currplayer==nextplayer[currplayer])
				{
					flag=false;
				}
			}
		}

		flag=false;
		for(int i=0; i<m; i++)
		{
			if(nextplayer[i]!=-1)
			{
				cout << (flag?" ":"");
				cout << i+1;
				flag = true;
			}
		}
		cout << endl;
	}
}