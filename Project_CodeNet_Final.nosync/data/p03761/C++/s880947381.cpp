#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <climits>
#include <set>
#include <deque>
#include <bitset>
//#include "mylib.h"

#define mod 1000000007
#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOREACH(i, v) for(auto i = v.begin(); i != v.end(); i++)
#define PRINT(n) cout << n << endl

using namespace std;
using ll = long long;

int X[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Y[] = {1, 1, 1, 0, -1, -1, -1, 0};

void solve() {
    int n, x[30], y[30];
    string s[55];
    cin >> n;
    REP(i, n)	cin >> s[i];
	REP(i, 26){
		x[i] = 0, y[i] = 0;
	}
	for(int i = 0; i < s[0].length(); i++){
		x[s[0][i]-'a']++;
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < s[i].length(); j++){
			y[s[i][j]-'a']++;
		}
		REP(k, 26) x[k] = min(x[k], y[k]);
		REP(k, 26) y[k] = 0;
	}

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < x[i]; j++){
			if(x[i] > 0){
				cout << (char)('a'+i);
			}
		}
	}
	cout << endl;
}

int main(){
    solve();
    return 0;
}
