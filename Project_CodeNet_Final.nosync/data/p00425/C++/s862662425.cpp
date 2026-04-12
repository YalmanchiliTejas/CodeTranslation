#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EACH(t,i,c) for(t::iretator i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

const double EPS = 1e-10;

int main() {
	int n, tmp;
	string str;

	while(cin >> n, n) {
		int ue = 1, shita = 6;
		int migi = 3, hidari = 4;
		int	mae = 5, ushiro = 2;
		int score = 1;		
		
		REP(i, n) {
			cin >> str;

			if(str == "North") {
				tmp = ue;
				ue = ushiro;
				ushiro = shita;
				shita = mae;
				mae = tmp;
			} else if(str == "East") {
				tmp = ue;
				ue = hidari;
				hidari = shita;
				shita = migi;
				migi = tmp;
			} else if(str == "West") {
				tmp = ue;
				ue = migi;
				migi = shita;
				shita = hidari;
				hidari = tmp;
			} else if(str == "South") {
				tmp = ue;
				ue = mae;
				mae = shita;
				shita = ushiro;
				ushiro = tmp;
			} else if(str == "Right") {
				tmp = mae;
				mae = hidari;
				hidari = ushiro;
				ushiro = migi;
				migi = tmp;
			} else if(str == "Left") {
				tmp = mae;
				mae = migi;
				migi = ushiro;
				ushiro = hidari;
				hidari = tmp;
			}

			score += ue;
		}
	
		cout << score << endl;
	}
}