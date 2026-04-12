#include <iostream>

using namespace std;

int main( void )
{
	int n;
	while(cin >> n, n) {
		int Max = 0, Min = 1001, Sum = 0;
		int i=n;
		while(i--) {
			int s;
			cin >> s;
			Sum += s;
			if(Max < s) Max = s;
			if(Min > s) Min = s;
		}
		int ave = (Sum - Max - Min) / (n - 2);
		cout << ave << endl;

	}
	return 0;
}