// 2012/07/13 Tazoe

#include <iostream>
using namespace std;

int main()
{
	while(true){
		int s1, s2;
		cin >> s1 >> s2;

		if(s1==0&&s2==0)
			break;

		char n_max = 'A';
		int s_max = s1+s2;

		cin >> s1 >> s2;
		if(s1+s2>s_max){
			n_max = 'B';
			s_max = s1+s2;
		}

		cin >> s1 >> s2;
		if(s1+s2>s_max){
			n_max = 'C';
			s_max = s1+s2;
		}

		cin >> s1 >> s2;
		if(s1+s2>s_max){
			n_max = 'D';
			s_max = s1+s2;
		}

		cin >> s1 >> s2;
		if(s1+s2>s_max){
			n_max = 'E';
			s_max = s1+s2;
		}

		cout << n_max << ' ' << s_max << endl;
	}

	return 0;
}