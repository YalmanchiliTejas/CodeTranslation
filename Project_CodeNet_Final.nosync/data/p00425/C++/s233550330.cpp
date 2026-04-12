#include <iostream>
#include <string>
using namespace std;

class Dice{
public:
	Dice( int f, int b, int u, int r, int d, int l ) :
		face( f ), back( b ), up( u ), right( r ), down( d ), left( l ){};

	int roll( string& dir ){
		int tmp;
		switch( dir[ 0 ] ){
			case 'N':
				tmp = face; face = down; down = back; back = up; up = tmp; break;
			case 'E':
				tmp = face; face = left; left = back; back = right; right = tmp; break;
			case 'S':
				tmp = face; face = up; up = back; back = down; down = tmp; break;
			case 'W':
				tmp = face; face = right; right = back; back = left; left = tmp; break;
			case 'R':
				tmp = up; up = left; left = down; down = right; right = tmp; break;
			case 'L':
				tmp = up; up = right; right = down; down = left; left = tmp; break;
			default:
				cout << "unknown" << endl;
		}

		return face;
	}

private:
	int face, back, up, right, down, left;
};

int main()
{
	int n;

	while( cin >> n && n ){
		int sum = 1;
		Dice dice( 1, 6, 5, 3, 2, 4 );

		for( int i = 0; i < n; ++i ){
			string s;
			cin >> s;
			sum += dice.roll( s );
		}

		cout << sum << endl;
	}

	return 0;
}