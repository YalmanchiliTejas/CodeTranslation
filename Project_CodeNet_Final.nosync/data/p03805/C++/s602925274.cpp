#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <memory.h>



using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORNUM(p, x) for (int num = p; num < (int)(x); ++num)
#define FORI(p, x) for (int i = p; i < (int)(x); ++i)
#define FORJ(p, x) for (int j = p; j < (int)(x); ++j)
#define FORK(p, x) for (int k = p; k < (int)(x); ++k)
#define FORL(p, x) for (int l = p; l < (int)(x); ++l)

typedef pair<int,int>P;
#define INF 1000000000
 
struct edge { 
	int from, to; 
	edge (int from, int to){
		this->from=from; this->to=to;
	}
};
 
int V,E;
typedef vector<edge> edges;
//vector<edges> G;

int n, m;
vector<pair<int, int> > e;

int main(){
	cin >> n >> m;
	FORI(0, m) {
		int u, v;
		cin >> u >> v; u--; v--;

		e.push_back(make_pair(u, v));
		e.push_back(make_pair(v, u));
	}
	int p[10];
	FORI(0, n)p[i] = i;
	int ans = 0;
	do {
		bool flg = true;
		FORI(0, n - 1) {
			if (e.end()==find(e.begin(), e.end(), make_pair(p[i],p[i+1]))) {
				flg = false;
				break;
			}
		}
		if (flg) {
			ans++;
		}
	} while (next_permutation(p + 1, p + n));
	cout << ans << endl;
	return 0;
}
