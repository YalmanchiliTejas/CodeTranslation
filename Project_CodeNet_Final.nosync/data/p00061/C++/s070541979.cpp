#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	int team_score[100 + 1] = {};
	int point[30 + 1] = {};
	int p, s, q;
	
	while(scanf("%d,%d", &p, &s) != EOF) {
		if(p == 0 && s == 0)   break;
		team_score[p] = s;
		++point[s];
	}
	
	while(cin >> q) {
		int rank = 0;
		s = 30;
		while(team_score[q] <= s) {
			if(point[s] != 0) {
				++rank;
			}
			--s;
		}
		cout << rank << endl;
	}
	
	return 0;
}
