// tsukasa_diary's programing contest code template
#include <bits/stdc++.h>
using namespace std;
// define
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for_rev(i,a,b) for(int i=a;i>=b;--i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) (int)a.size()
// typedef
typedef long long lint;
typedef double Double;
typedef pair<int, int> pii;
//
typedef vector< int > Array;
typedef vector< Array > Matrix;
typedef vector< Double > DArray;
typedef vector< DArray > DMatrix;
typedef vector< string > SArray;
typedef vector< pii > PArray;
// popcount
inline int POPCNT(int _x) { return __builtin_popcount(_x); }
inline int POPCNT(lint _x) { return __builtin_popcountll(_x); }
// inf
const int iINF = 1L << 30;
const lint lINF = 1LL << 60;
// eps
Double EPS = 1e-9;
// in range
inline bool in_range(int _v, int _mx, int _mi) { return _mi <= _v && _v < _mx; }
inline bool in_range(Double _v, Double _mi, Double _mx) { return -EPS < _v - _mi && _v - _mx < EPS; }
inline bool in_range(int _x, int _y, int _W, int _H) { return 0 <= _x && _x < _W && 0 <= _y && _y < _H; }
// neighbor clockwise
const int DX[4] = {0,1,0,-1}, DY[4] = {-1,0,1,0};
const int DX_[8] = {0,1,1,1,0,-1,-1,-1}, DY_[8] = {-1,-1,0,1,1,1,0,-1};
// variable update
inline void modAdd(int& _a, int _b, int _m) { _a = (_a + _b) % _m; }
inline void modAdd(lint& _a, lint _b, lint _m) { _a = (_a + _b) % _m; }
inline void minUpdate(int& _a, int _b) { _a = min(_a, _b); }
inline void minUpdate(lint& _a, lint _b) { _a = min(_a, _b); }
inline void maxUpdate(int& _a, int _b) { _a = max(_a, _b); }
inline void maxUpdate(lint& _a, lint _b) { _a = max(_a, _b); }

// Dice
enum DICE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };

const int front_by_tr[6][6] = {
	{ -1, 4, 2, 5, 3, -1 },
	{ 3, -1, 6, 1, -1, 4 },
	{ 5, 1, -1, -1, 6, 2 },
	{ 2, 6, -1, -1, 1, 5 },
	{ 4, -1, 1, 6, -1, 3 },
	{ -1, 3, 5, 2, 4, -1 }
};

struct Dice {
private:
	int dice[6];
	
public:
	Dice() {
		dice[TOP] = 1; dice[BOTTOM] = 6;
		dice[FRONT] = 2; dice[BACK] = 5;
		dice[RIGHT] = 3; dice[LEFT] = 4;
	}
	
	Dice(int _t, int _r) {
		dice[TOP] = _t; dice[BOTTOM] = 7 - _t;
		dice[RIGHT] = _r; dice[LEFT] = 7 - _r;
		dice[FRONT] = front_by_tr[_t][_r]; dice[BACK] = 7 - dice[FRONT];
	}
	
	void north_roll() {
		int _t = dice[TOP];
		dice[TOP] = dice[FRONT];
		dice[FRONT] = dice[BOTTOM];
		dice[BOTTOM] = dice[BACK];
		dice[BACK] = _t;
	}
	
	void south_roll() {
		int _b = dice[BOTTOM];
		dice[BOTTOM] = dice[FRONT];
		dice[FRONT] = dice[TOP];
		dice[TOP] = dice[BACK];
		dice[BACK] = _b;
	}
	
	void east_roll() {
		int _t = dice[TOP];
		dice[TOP] = dice[LEFT];
		dice[LEFT] = dice[BOTTOM];
		dice[BOTTOM] = dice[RIGHT];
		dice[RIGHT] = _t;
	}
	
	void west_roll() {
		int _t = dice[TOP];
		dice[TOP] = dice[RIGHT];
		dice[RIGHT] = dice[BOTTOM];
		dice[BOTTOM] = dice[LEFT];
		dice[LEFT] = _t;
	}
	
	// pivot is top
	void right_roll() {
		int _r = dice[RIGHT];
		dice[RIGHT] = dice[BACK];
		dice[BACK] = dice[LEFT];
		dice[LEFT] = dice[FRONT];
		dice[FRONT] = _r;
	}
	
	void left_roll() {
		int _l = dice[LEFT];
		dice[LEFT] = dice[BACK];
		dice[BACK] = dice[RIGHT];
		dice[RIGHT] = dice[FRONT];
		dice[FRONT] = _l;
	}
	
	int dice_at(enum DICE d) {
		return dice[d];
	}
};

int n;

void solve() {
	Dice dice;
	int ans = 1;
	
	for_(i,0,n) {
		string str; cin >> str;
		
		if (str == "North") dice.north_roll();
		if (str == "East") dice.east_roll();
		if (str == "South") dice.south_roll();		
		if (str == "West") dice.west_roll();
		if (str == "Right") dice.right_roll();
		if (str == "Left") dice.left_roll();
		
		ans += dice.dice_at(TOP);
	}
	
	cout << ans << endl;
}

int main() {
	while (cin >> n, n) {
		solve();
	}
	return 0;
}