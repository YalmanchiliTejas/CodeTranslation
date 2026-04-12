#include <bits/stdc++.h>

using namespace std;

class TeamInfo {
public:
	string name;
	int totalScore;
};

TeamInfo TeamData[10];

bool cmp(const TeamInfo &t1, const TeamInfo &t2) {
	return t1.totalScore > t2.totalScore;
}

int main() {
	int n, w, l, d;
	bool flag = false;

	while (cin >> n, n) {
		//memset(TeamData, 0, sizeof(TeamData));
		if (flag) {
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			cin >> TeamData[i].name;
			cin >> w >> l >> d;
			TeamData[i].totalScore = w * 3 + d;
		}
		sort(TeamData, TeamData + n, cmp);
		for (int i = 0; i < n; i++) {
			cout << TeamData[i].name << "," << TeamData[i].totalScore << endl;
		}
		flag = true;
	}

	return 0;
}
