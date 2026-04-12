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
	int from, to,cap,rev; 
	edge (int from, int to, int cap, int rev){
		this->from=from; this->to=to; this->cap=cap; this->rev=rev;
	}
};
 
int V,E;
typedef vector<edge> edges;
vector<edges> G;



int main(){
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;

	return 0;
}
