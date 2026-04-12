#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class Team{
public:
	string name;
	int win;
	int lose;
	int draw;
	int point;

};
bool operator<( const Team& rhs, const Team& lhs ){
	return ( rhs.point < lhs.point );
}
bool operator>( const Team& rhs, const Team& lhs ){
	return ( rhs.point > lhs.point );
}
int main(int argc, char const* argv[])
{
	int num;
	Team team[10];
	bool a = false;

	while( cin >> num && num != 0 ){
		if( a == true ) cout << endl;
		a = true;
		for( int i = 0;i < num;i++ ){
			cin >> team[i].name >> team[i].win >> team[i].lose >> team[i].draw;
			team[i].point = team[i].win * 3 + team[i].draw;
		}
		stable_sort( team, team + num, greater<Team>() );
		for( int i = 0;i < num;i++ ) cout << team[i].name << "," << team[i].point << endl;
	}
	return 0;
}