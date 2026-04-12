#include <iostream>
#include <string>
using namespace std;

struct Team{
	string name;
	int win;
	int lose;
	int draw;
	int point;
};

void sort( Team* teams, int n )
{
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j < n - 1; ++j ){
			if( teams[ j ].point < teams[ j + 1 ].point ){
				Team t = teams[ j ];
				teams[ j ] = teams[ j + 1 ];
				teams[ j + 1 ] = t;
			}
		}
	}
}

int main()
{
	int teamQuantity;
	bool first = true;

	while( cin >> teamQuantity ){
		if( teamQuantity == 0 ){
			break;
		}
		Team* teams = new Team[ teamQuantity ];
		for( int i = 0; i < teamQuantity; ++i ){
			cin >> teams[ i ].name >> teams[ i ].win >> teams[ i ].lose >> teams[ i ].draw;
			teams[ i ].point = teams[ i ].win * 3 + teams[ i ].draw;
		}
		sort( teams, teamQuantity );

		if( first ){
			first = false;
		}else{
			cout << endl;
		}

		for( int i = 0; i < teamQuantity; ++i ){
			cout << teams[ i ].name << "," << teams[ i ].point << endl;
		}
		delete[] teams;
	}
	return 0;
}