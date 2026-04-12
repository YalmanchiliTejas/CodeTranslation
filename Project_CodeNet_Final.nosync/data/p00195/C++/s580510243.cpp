#include <iostream>

using namespace std;

int main(void)
{
	int a,b,max;
	char name;

	while( cin >> a >> b && a != 0 && b != 0 ){
		max = a + b;
		name = 'A';

		for( int i = 0;i < 4;i++ ){
			cin >> a >> b;
			if( max < a + b ){
				max = a + b;
				name = 'B' + i;
			}
		}

		cout << name << " " << max << endl;
	}

	return 0;
}