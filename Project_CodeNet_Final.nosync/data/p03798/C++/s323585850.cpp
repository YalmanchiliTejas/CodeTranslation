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
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1<<29)
 
struct edge { 
	int from, to; 
	edge (int from, int to){
		this->from=from; this->to=to;
	}
};
 
int V,E;
typedef vector<edge> edges;
vector<edges> G;

int n;
string s;
string ans;
char anim[2] = { 'S','W' };

char nextch(char cur, char left, char a) {
	if ((cur == 'S'&& a == 'o') || (cur == 'W'&& a == 'x'))
		return left;

	if ((cur == 'S'&& a == 'x') || (cur == 'W'&& a == 'o'))
		return left=='S'?'W':'S';

}

bool check(char cur, char left, char right, char a) {
	if ((cur == 'S' && a == 'o') || (cur=='W' && a=='x')) {
		return left == right;
	}
	if ((cur == 'S' && a == 'x') || (cur == 'W' && a == 'o')) {
		return left != right;
	}
}

bool go(char a, char b) {
	ans.clear();
	ans.resize(s.size());
	ans[0] = a; ans[1] = b;
	FOR(i, 2, n-1) {
		ans[i]=nextch(ans[i - 1], ans[i - 2], s[i - 1]);
	}
	bool flg = check(ans[0], ans[n - 1], ans[1], s[0]);
	flg = flg & check(ans[n - 1], ans[n - 2], ans[0], s[n - 1]);
	return flg;
}

int main(){
	cin >> n >> s;
	ans.resize(s.size());
	
	rep(i, 2) {
		rep(j, 2) {
			if (go(anim[i], anim[j])) {
				rep(k, ans.size()) {
					cout << ans[k];
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
