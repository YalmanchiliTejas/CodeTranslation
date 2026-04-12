#include<iostream>
#include<string>

using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)

char _left[] = "qwertasdfgzxcvb";


int main()
{
	string str;
	while(cin >> str,str != "#")
	{
		int ans = 0;
		int hand = -1;
		REP(i,str.size())
		{
			bool flag = false;
			REP(j,15)
			{
				if(str[i] == _left[j])
				{
					if(hand == 0)
					{
						ans++;
					}
					hand = 1;
					flag = true;
				}
			}
			if(!flag)
			{
				if(hand == 1)ans++;
				hand = 0;
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}