#include <iostream>
#include <string>

using namespace std;

int main( void )
{
	int n;
	while(cin >> n, n) {
		int map[][3] = { { -1, 5, -1 },
						 {  4, 6,  3 },
						 { -1, 2, -1 },
						 { -1, 1, -1 }
		};
		int sum = 1;
		while(n--) {
			string str;
			cin >> str;
			switch(str[0]) {
			case 'N':
				for(int i=1; i < 4; ++i) swap(map[0][1], map[i][1]);
				break;
			case 'E':
				for(int i=2; i > -1; --i) swap(map[3][1], map[1][i]);
				break;
			case 'W':
				for(int i=0; i <  3; ++i) swap(map[3][1], map[1][i]);
				break;
			case 'S':
				for(int i=2; i > -1; --i) swap(map[3][1], map[i][1]);
				break;
			case 'R':
				swap(map[1][2], map[2][1]);
				swap(map[1][2], map[1][0]);
				swap(map[1][2], map[0][1]);
				break;
			case 'L':
				swap(map[1][0], map[2][1]);
				swap(map[1][0], map[1][2]);
				swap(map[1][0], map[0][1]);
				break;
			}
			sum += map[3][1];
		}
		cout << sum << endl;
	}
	return 0;
}