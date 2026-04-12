//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

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

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code
int main(int argc, char const* argv[])
{
	int h,w;
	cin >> h >> w;
	vector<vector<char>> a(h,vector<char>(w));
	VVL b(h,VL(w,0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		bool allw = true;
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				allw = false;
			}
		}
		if (allw) {
			for (int j = 0; j < w; j++) {
				b[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < w; i++) {
		bool allw = true;
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '#') {
				allw = false;
			}
		}
		if (allw) {
			for (int j = 0; j < h; j++) {
				b[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		bool allw = true;
		for (int j = 0; j < w; j++) {
			if (b[i][j] == 0) {
				cout << a[i][j];
				allw = false;
			}
		}
		if (!allw) {
			cout << endl;
		}
	}
	return 0;
}

