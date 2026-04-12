// 2011/01/13 Tazoe

#include <iostream>
using namespace std;

int main()
{
	while(true){
		int s[5][2];
		cin >> s[0][0] >> s[0][1];
		if(s[0][0]==0&&s[0][1]==0)
			break;

		for(int i=1; i<5; i++)
			cin >> s[i][0] >> s[i][1];

		int i_max = 0;
		int s_max = s[0][0]+s[0][1];
		for(int i=1; i<5; i++)
			if(s_max<s[i][0]+s[i][1]){
				i_max = i;
				s_max = s[i][0]+s[i][1];
			}

		cout << (char)('A'+i_max) << ' ' << s_max << endl;
	}

	return 0;
}