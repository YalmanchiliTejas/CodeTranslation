#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

bool mp[10][10] = {};
int h, w;
int how = 0;

bool check(int x, int y, int num){
	if(x == w - 1 && y == h - 1){
		if(num == how) return true;
		else return false;
	}

	bool a = false, b= false;
	if(x + 1 < w && mp[x + 1][y]){
		a = check(x + 1, y, num + 1);
	}
	if(y + 1 < h && mp[x][y + 1]){
		b = check(x, y + 1, num + 1);
	}

	return (a || b);
}

int main() {
	cin >> h >> w;
	string str;
	REP(i, h){
		cin >> str;
		REP(j, str.size()){
			if(str[j] == '#') {
				mp[j][i] = true;
				how++;
			}else{
				mp[j][i] = false;
			}
		}
	}

	bool ans = check(0, 0, 1);
	if(ans) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}