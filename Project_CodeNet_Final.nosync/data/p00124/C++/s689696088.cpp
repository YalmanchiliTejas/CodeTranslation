/*
	AOJ_0124: League Match Score Sheet
*/
#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<vector>

using namespace std;

class Teams {
private:
	int num;
	string name;
	int score;
public:
	Teams(){
		score = 0;
	}
	Teams(int n, string c, int s){
		num = n;
		name = c;
		score = s;
	}
	void showTeams(void) {
		cout << name << ',' << score << endl;
	}
	bool operator<(const Teams& another) const {
		if (score != another.score) { return score > another.score; }
		return num < another.num;
	}
};

int main(void) {
	int N, c_win, c_draw, c_lose, c_score;
	string c_name;
	bool isDo = false;

	while (1) {
		vector<Teams> T;

		cin >> N;
		if (N == 0) { break; }
		if (isDo == true) { cout << endl; }

		for (int i = 0; i < N; i++) {
			cin >> c_name >> c_win >> c_lose >> c_draw;
			c_score = c_win * 3 + c_draw;
			T.push_back( Teams(i, c_name, c_score) );
		}
		sort(T.begin(), T.end());
		vector<Teams>::iterator it = T.begin();
		while (it != T.end()) {
			it->showTeams();
			it++;
		}
		isDo = true;
	}

	return 0;
}