#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ST_team {
public:
	int no;
	int score;
	int rank;
public:
	ST_team() { no = 0; score = 0; rank = 0; }
	ST_team(int n, int s) { no = n; score = s; rank = 0; }
};
typedef struct ST_team team;

bool desc_score(const ST_team& t1, const ST_team& t2) { return t1.score > t2.score; }
bool asc_no(const ST_team& t1, const ST_team& t2) { return t1.no < t2.no; }

int main()
{
	vector<team> t;
	char dummy;
	int no, score;
	
	while (true) {
		cin >> no >> dummy >> score;
		if (no == 0 && score == 0) break;
		team tmp_t(no, score);
		t.push_back( tmp_t );
	}
	
	sort(t.begin(), t.end(), desc_score);
	
	int curr_rank = 0;
	int curr_score = 100;
	for (vector<team>::iterator it = t.begin(); it != t.end(); it++) {
		if ( curr_score > (*it).score ) { curr_rank++; curr_score = (*it).score; }
		(*it).rank = curr_rank;
	}
	
	sort(t.begin(), t.end(), asc_no);
	
	//for (vector<team>::iterator it = t.begin(); it != t.end(); it++) cout << (*it).no << ":" << (*it).score << "," << (*it).rank << endl;
	
	int q;
	while (cin >> q) cout << t.at(q-1).rank << endl;
	
	return 0;
}