#include <iostream>
using namespace std;

int main()
{
	int s1,s2,ms,mn;
	
	while(cin >> s1 >> s2, (s1||s2))
	{
		ms = 0; mn = s1+s2;
		for(int i=1; i<5; i++)
		{
			cin >> s1 >> s2;
			if(s1+s2>mn)
			{
				ms = i;
				mn = s1+s2;
			}
		}
		cout << (char)('A'+ms) << " " << mn << endl;
	}

	return 0;
}