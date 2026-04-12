#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Team{
	public:
		int num;
		int score;
		Team(int n, int s){
			num = n;
			score = s;
		}
		friend bool operator < ( const Team& a, const Team& b){
			return a.score < b.score;
		}
		friend bool operator > ( const Team& a, const Team& b){
			return a.score > b.score;
		}
};

int main(){
	vector<Team> teams;
	int n, score;
	while (~scanf("%d,%d", &n, &score)) {
		if(n == 0 && score == 0){
			break;
		}
		teams.push_back(Team(n, score));
	}
	
	sort(teams.begin(), teams.end(), greater<Team>());

	while (cin >> n) {
		int lastScore = -1;
		int rank = 0;
		for (int i = 0; i < teams.size(); i++) {
			if (lastScore != teams[i].score) {
				rank++;
				lastScore = teams[i].score;
			}
			if (n == teams[i].num) {
				cout << rank << endl;
			}
		}
	}
	return 0;
}