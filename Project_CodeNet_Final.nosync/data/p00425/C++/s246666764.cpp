#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Dice{
private:
	static const int _roll[4][6], _turn[2][6];
public:
	vector<int> value;
	// 1-6 : top, near, right, left, far, bottom 

	Dice(){
		value.resize(6);
		for (int i = 0; i < 6; ++i) value[i] = i;
	}

	void roll(int dir){ // N, E, W, S
		vector<int> nxt(6);
		for (int i = 0; i < 6; ++i){
			nxt[i] = value[_roll[dir][i]];
		}
		value = nxt;
	}

	void turn(int dir){ // L, R
		vector<int> nxt(6);
		for (int i = 0; i < 6; ++i){
			nxt[i] = value[_turn[dir][i]];
		}
		value = nxt;
	}

	int &operator[](int i){
		return value[i];
	}
};

const int Dice::_roll[4][6] = {
	{ 1, 5, 2, 3, 0, 4 }, // North
	{ 3, 1, 0, 5, 4, 2 }, // East
	{ 2, 1, 5, 0, 4, 3 }, // West
	{ 4, 0, 2, 3, 5, 1 }, // South
};

const int Dice::_turn[2][6] = {
	{ 0, 3, 1, 4, 2, 5 }, // Left
	{ 0, 2, 4, 1, 3, 5 }, // Right
};


int main(){	
	map<char, int> m;
	for (int i = 0; i < 6; ++i) m["NEWSLR"[i]] = i;

	int n;
	while (cin >> n, n){
		Dice d;
		int ans = 1;
		while (n--){
			string s;
			cin >> s;
			int x = m[s[0]];
			x < 4 ? d.roll(x) : d.turn(x - 4);
			ans += d[0]+1;
		}
		cout << ans << endl;
	}

	return 0;
}