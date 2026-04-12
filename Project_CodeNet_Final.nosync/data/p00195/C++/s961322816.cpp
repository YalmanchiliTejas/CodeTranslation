#include <iostream>
using namespace std;
int main()
{

	while(true){

		int s1,s2;
		int max = 0,x = 0;

		cin >> s1 >> s2;

		if(s1 == 0 && s2 == 0)
			break;

		max = s1 + s2;
	
		for(int i=1 ;i<5 ;i++){

			cin >> s1 >> s2;

			if(max < (s1+s2)){
				max = s1 + s2;
				x = i;
			}
		}


		if(x==0)
			cout << 'A' << ' ' << max << endl;
		if(x==1)
			cout << 'B' << ' ' << max << endl;
		if(x==2)
			cout << 'C' << ' ' << max << endl;
		if(x==3)
			cout << 'D' << ' ' << max << endl;
		if(x==4)
			cout << 'E' << ' ' << max << endl;
		}
		return 0;
}