#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

struct Team{
	string name;
	int score;
	bool operator>(const Team &t) const { return (score > t.score); }
};

int main(void){
	bool bFirst = true;
	while( true ){
		int n;
		vector<Team> vTeam;

		cin >> n;
		if( n == 0 )
			break;

		if( !bFirst )
			cout << '\n';
		else
			bFirst = false;

		for(int i = 0 ; i < n; ++i){
			Team tmp;
			int win, lose, draw;

			cin >> tmp.name >> win >> lose >> draw;
			tmp.score = win * 3 + lose * 0 + draw * 1;
			vTeam.push_back( tmp );
		}
		stable_sort( vTeam.begin(), vTeam.end(), greater<Team>() );
		
		for(unsigned int i = 0; i < vTeam.size(); ++i)
			cout << vTeam[i].name << ',' << vTeam[i].score << '\n';
	}
	return 0;
}