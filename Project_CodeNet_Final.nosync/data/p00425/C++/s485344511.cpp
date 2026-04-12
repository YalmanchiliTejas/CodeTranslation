#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define REP(i, b, e) for (int i = (b); i < (e); i++)
#define rep(i, n) REP(i, 0, n)

#define dump(x) cout << #x << ":" << x << endl

int n;

typedef enum {
	TOP,
	BOTTOM,
	FRONT,
	BACK,
	RIGHT,
	LEFT
} Surface;

class Dice
{
private:
	int surface[6];
public:
	Dice() {
		surface[TOP] = 1;
		surface[FRONT] = 2;
		surface[RIGHT] = 3;
		surface[BOTTOM] = 6;
		surface[BACK] = 5;
		surface[LEFT] = 4;
	}

	void rotate(Surface a, Surface b, Surface c, Surface d)
	{
		int buf = surface[a];
		surface[a] = surface[b];
		surface[b] = surface[c];
		surface[c] = surface[d];
		surface[d] = buf;
	}

	void north()	{ rotate(TOP, FRONT, BOTTOM, BACK); }
	void east()		{ rotate(TOP, LEFT, BOTTOM, RIGHT); }
	void west()		{ rotate(TOP, RIGHT, BOTTOM, LEFT); }
	void south()	{ rotate(TOP, BACK, BOTTOM, FRONT); }
	void right()	{ rotate(FRONT, RIGHT, BACK, LEFT); }
	void left()		{ rotate(FRONT, LEFT, BACK, RIGHT); }

	int operator[](Surface idx)
	{
		return surface[idx];
	}
};

int main()
{
	while (cin >> n, n) {
		Dice dice;
		int ans = dice[TOP];
		rep(t, n) {
			string direc;
			cin >> direc;
			if (direc == "North")
				dice.north();
			else if (direc == "East")
				dice.east();
			else if (direc == "South")
				dice.south();
			else if (direc == "West")
				dice.west();
			else if (direc == "Right")
				dice.right();
			else if (direc == "Left")
				dice.left();
			ans += dice[TOP];
		}
		cout << ans << endl;
	}
	return 0;
}