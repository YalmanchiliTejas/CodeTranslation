#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

class Dice{//サイコロを扱うクラス
public:
	int t, n, e;//top, north, east
	Dice(int _t, int _n, int _e){
		t = _t;
		n = _n;
		e = _e;
	}
	void North(void){
		int nt, nn;
		nt = 7-n;
		nn = t;
		n = nn;
		t = nt;
	}
	void South(void){
		int nt, nn, ne;
		nt = n;
		nn = 7-t;
		t = nt;
		n = nn;
	}
	void East(void){
		int nt, nn, ne;
		ne = t;
		nt = 7-e;
		e = ne;
		t = nt;
	}
	void West(void){
		int nt, nn, ne;
		ne = 7-t;
		nt = e;
		e = ne;
		t = nt;
	}
	void Left(void){
		int nt, nn, ne;
		nn = e;
		ne = 7-n;
		e = ne;
		n = nn;
	}
	void Right(void){
		int nn, ne;
		nn = 7-e;
		ne = n;
		e = ne;
		n = nn;
	}
};

int main(){
	while(1){
		int n;
		Dice d(1,5,3);
		cin >> n;
		if(n==0)return 0;
		int ret = 1;
		REP(i, n){
			string str;
			cin >> str;
			if(str == "North")d.North();
			else if(str == "South")d.South();
			else if(str == "East")d.East();
			else if(str == "West")d.West();
			else if(str == "Left")d.Left();
			else if(str == "Right")d.Right();
			ret += d.t;
		}
		cout << ret << endl;
	}
}