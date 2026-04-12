#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
	char t;
	map<char, int> val;
	FOR(i,2,9) val[i+'0'] = i;
	val['T'] = 10;
	val['J'] = 11;
	val['Q'] = 12;
	val['K'] = 13;
	val['A'] = 14;

	while (cin >> t && t != '#'){
		string s[4][13];
		REP(i,4) REP(j,13) cin >> s[i][j];
		int l = 0;
		int win[4] = {};
		REP(j,13){
			int a[4];
			REP(i,4){
				a[i] = val[s[i][j][0]];
				if (s[i][j][1] == t) a[i] += 15;
				else if (s[i][j][1] != s[l][j][1]) a[i] = 0;
			}
			REP(i,4){
				if (a[i] > a[l]) l = i;
			}
			win[l]++;
		}

		int ew = win[1]+win[3], ns = win[0]+win[2];
		if (ew > ns) printf("EW %d\n", ew - 6);
		else printf("NS %d\n", ns - 6);

	}
    return 0;
}