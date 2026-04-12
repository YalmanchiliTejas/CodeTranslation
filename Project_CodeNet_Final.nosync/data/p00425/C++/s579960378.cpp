#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

string dir[6] = {"North", "East", "West", "South", "Right", "Left"};

int roll[6][6] = {
	{5, 1, 3, 4, 6, 2},
	{3, 2, 6, 1, 5, 4},
	{4, 2, 1, 6, 5, 3},
	{2, 6, 3, 4, 1, 5},
	{1, 4, 2, 5, 3, 6},
	{1, 3, 5, 2, 4, 6},
};

vector< int > initDice() {
	vector< int > res;
	for_(i,1,7) res.push_back(i);
	return res;
}

vector< int > rollDice(vector< int > dice, int d) {
	vector< int > res(6);
	for_(i,0,6) res[roll[d][i] - 1] = dice[i];
	return res;
}

int main() {
	int N;
	
	while (cin >> N, N) {
		vector< int > dice = initDice();
		
		int ans = 1;
		for_(i,0,N) {
			string S;
			cin >> S;
			dice = rollDice(dice, find(dir, dir + 6, S) - dir);
			ans += dice[0];
		}
		cout << ans << endl;
	}
}