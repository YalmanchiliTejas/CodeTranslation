#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <bitset>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1 << 27;
//////////////////////////////
// ????????????
int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};
int H[6][6] = {
    {1,5,2,3,0,4}, // North : ?\\????§????   ( y:-1 )
    {3,1,0,5,4,2}, // East  : ???????§????   ( x:+1 )
    {2,1,5,0,4,3}, // West  : ???????§????   ( x:-1 )
    {4,0,2,3,5,1}, // South : ??????????§???? ( y:+1 )
    {0,2,4,1,3,5}, // Right : ?????????????????¢ (?§??????????)
    {0,3,1,4,2,5}  // Left  : ?????????????????¢ (?§??????????)
};
// ???????????????????????????
// d[0] := top,   d[1] := front
// d[2] := right, d[3] := left
// d[4] := back,  d[5] := bottom
enum{TOP, FRONT, RIGHT, LEFT, BACK, BOTTOM};
struct Cube{
    vector<int> d;
    // ???????????????????????§?????????
    Cube(vector<int> v){
        if( v.size() == 6 )
            d = v;
        else
            d = vector<int>(6);
    }
    Cube(){ d = vector<int>(6); }
    // dir?????????????????¢ (????????¨??????)
    Cube roll(int dir){
        vector<int> d_(6);
        for(int i = 0 ; i < 6 ; i++ ){
            d_[i] = d[ H[dir][i] ];
        }
        return Cube(d_);
    }
};
int main() {
	vi v;
	REP(i, 6)
		v.pb(i+1);
	int n;
	while(cin >> n, n) {
		Cube c(v);
		int sum = 1;
		while(n--) {
			string in; cin >> in;
			if(in[0] == 'N')
				c = c.roll(0);
			else if(in[0] == 'S')
				c = c.roll(3);
			else if(in[0] == 'E')
				c = c.roll(1);
			else if(in[0] == 'W')
				c = c.roll(2);
			else if(in[0] == 'R')
				c = c.roll(4);
			else if(in[0] == 'L')
				c = c.roll(5);
			sum += c.d[0];
		}
		cout << sum << endl;
	}
	return 0;
}