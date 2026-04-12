#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Team {
	string name;
	int score, no;
	Team(const string &na, int sc, int no) : name(na), score(sc), no(no) {}

	bool operator <(const Team &t) const {
		if(score != t.score) return score > t.score;
		return no < t.no;
	}
};

int main() {
	bool first = true;
	for(int N; cin >> N, N; ) {
		if(first) first = false;
		else cout << endl;
		vector<Team> v;
		for(int i = 0; i < N; i++) {
			string s;
			int w, l, d;
			cin >> s >> w >> l >> d;
			v.push_back(Team(s, 3 * w + d, i));
		}
		sort(v.begin(), v.end());

		for(auto it = v.begin(); it != v.end(); ++it) {
			cout << it->name << ',' << it->score << endl;
		}
	}
}