
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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

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

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << '=' << (x) << endl;
#define debug(x) cerr << #x << '=' << (x) << '('<<'L' << __LINE__ << ')' << ' ' << __FILE__ << endl;

bool cango[8][8];
bool visited[8];
int main() {

	int N, M;
	cin >> N >> M;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cango[a][b]=cango[b][a] = true;
		
	}
	VI X(N);
	REP(i, N) {
		X[i] = i;
	}
	int num = 0;
	do {
		

		CLR(visited);
		visited[X[0]] = true;
		bool all = true;

		for (int i = 0; i < SZ(X) - 1; i++) {
			if (cango[X[i]][X[i + 1]] == false) {
				goto NEXT;
			}
			visited[X[i + 1]] = true;
		}
		REP(i, SZ(X)) {
			if (!visited[i]) {
				goto NEXT;
			}
		}
		num++;
	NEXT:;
	} while (next_permutation(X.begin()+1,X.end()));
	cout << num << endl;

}