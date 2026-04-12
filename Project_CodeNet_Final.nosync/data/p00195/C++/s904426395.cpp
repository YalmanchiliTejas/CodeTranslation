// 2011/07/31 Tazoe

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

		int max_i = 0;
		int max_s = s[0][0]+s[0][1];
		for(int i=1; i<5; i++)
			if(s[i][0]+s[i][1]>max_s){
				max_i = i;
				max_s = s[i][0]+s[i][1];
			}

		cout << (char)('A'+max_i) << ' ' << max_s << endl;
	}

	return 0;
}