// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <locale>
#include <cctype>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef map<int, int> MAPII;
typedef vector<pair<int, int> > VPII;
typedef multimap<int, string, greater<int> > MuMIS;

#define MP make_pair
#define fastIO	cin.tie(0); ios::sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//for gcc (未test)
// #define FOREACH_IT(it,c)	for(typeof(c)::iterator it=(c).begin(); it!=(c).end(); ++it)
//for Visual Studio
#define foreach_it(type,it,c) for(type::iterator it=c.begin(), c_end=c.end(); it!=c_end; ++it)

// ------------------- include, typedef, define END. -------------------

void solve(MuMIS &result){
	foreach_it(MuMIS, it, result){
		cout << (*it).second << "," << (*it).first << endl;
	}
}

int main(){
	fastIO;
	int n, a = 0, b = 0, c = 0;
	string teamName;
	cin >> n;
	while (n){
		MuMIS result;
		while (n--){
			cin >> teamName >> a >> b >> c;
			result.insert(MP(a * 3 + c, teamName));
		}
		solve(result);
		cin >> n;
		if (n)
			cout << endl;
	}
	return 0;
}